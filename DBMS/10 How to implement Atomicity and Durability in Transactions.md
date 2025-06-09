## Implementing Atomicity and Durability in Transactions

---

### 1. Recovery Mechanism Component 🔄

Supports both **atomicity** and **durability** by ensuring that either *all* of a transaction’s effects are reflected or *none* are, and that once committed, effects survive crashes.

---

### 2. Shadow-Copy Scheme 🗃️

1. **Idea**

   * Make a *complete* copy of the database (the “new DB”) before applying any updates.
   * Keep the original as a “shadow copy” untouched until commit.

2. **Assumption**

   * Only one transaction (T) is active at a time.

3. **Mechanism**

   1. A `db-pointer` on disk always points to the **current** DB image.
   2. When T wants to update:

      * Create **new DB copy**.
      * Apply all updates to this new copy.
   3. If T **aborts**:

      * Delete new copy → original remains intact.
   4. If T **commits**:

      1. OS flushes all pages of new copy to disk.
      2. **Atomically** update the `db-pointer` to new copy location.
      3. Delete old copy.

4. **Atomicity**

   * If T fails *before* pointer swap, old DB stands.
   * Abort by simply discarding new copy.
   * ⇒ **All or none**.

5. **Durability**

   * If system crashes *before* pointer swap, pointer still references old DB → T’s effects vanish.
   * If crash *after*, pointer references new DB → on restart the new state is used.

6. **Key Requirement**

   * `db-pointer` update must be atomic.
   * Disks guarantee atomic writes at the block/sector level → store pointer within one sector.

> **⚠️ Inefficient:** copying the entire DB per transaction!

---

```ascii
          +------------------+           +------------------+
 Old DB ← |   Shadow Copy    | ←—— db-pointer —— New DB Copy
          +------------------+           +------------------+
                ▲                             ▲
                │                             │
               (delete)                   (write)
```

---

### 3. Log-Based Recovery Methods 📝

Maintain a **stable log** of every operation, enabling efficient undo/redo without full DB copies.

| Aspect                   | Shadow-Copy Scheme        | Log-Based Recovery        |
| ------------------------ | ------------------------- | ------------------------- |
| **Storage Overhead**     | Entire DB per transaction | Only log records          |
| **Performance**          | Very poor (full copy)     | Much better (append-only) |
| **Atomicity Mechanism**  | Pointer swap              | Undo via *old values*     |
| **Durability Mechanism** | Pointer persists          | Redo via *new values*     |
| **Failure Handling**     | Implicit via pointer      | Explicit undo/redo steps  |

---

#### 3.1 Deferred DB Modifications ⏳

* **Record** all intended DB updates in the log *before* writing to the database.
* **Do not** apply to DB until T commits.
* On **commit**:

  1. Scan log, **apply** deferred writes to DB.
  2. If crash occurs during this, perform **redo** on remaining.
* If T **aborts/crashes** before commit: ignore its log entries → no writes ever occur.

```text
T start
 └─▶ append “modify X to X′” in log
 ... (more ops)
 commit
 └─▶ apply all logged modifications to DB
```

---

#### 3.2 Immediate DB Modifications ⚡

* **Apply** each update to DB *as soon as* it happens, but *only after* its log record is on stable storage.
* Active-T writes = **uncommitted modifications**.

1. **Before** update:

   * Write log record: ⬅️ old value, new value
2. **Crash / Abort** *before* commit:

   * Use **old-value** fields to **undo**.
3. **Commit**: mark in log.
4. **Crash** *after* commit:

   * Use **new-value** fields to **redo** any missing writes.

```sql
-- Pseudocode for each update:
WRITE-LOG( T.id, page, offset, old_value, new_value )
FORCE-LOG-TO-DISK()
APPLY-UPDATE-TO-DB(page, offset, new_value)

-- On recovery:
FOR each log record in reverse order UNTIL last checkpoint
  IF record.T is uncommitted
    UNDO(record)   -- restore old_value
FOR each log record in forward order
  IF record.T is committed
    REDO(record)   -- apply new_value
```

---

### 4. Comparative ASCII Timeline

```ascii
Time →
┌────────────────────┐   ┌───────────────┐   ┌─────────────────┐
│ Deferred Modifications │ │ Commit Point │ │ Crash Recovery │
└────────────────────┘   └───────────────┘   └─────────────────┘
   |                         
   | log entries only          
   v                         
 apply writes ←┐
               └─── if committed, else ignore
```

---

#### ✅ Key Takeaways

* **Shadow-copy**: conceptually simple, but **inefficient**.
* **Log-based**: industry standard; supports both **deferred** and **immediate** strategies.
* **Atomic pointer updates** and **stable storage logs** are foundational to ensuring ACID’s A & D properties.
Here’s the “next”—all three flavors in one place! 🎉

---

## 1. Real-Life Example: Online Banking 🏦

Imagine **Alice** transfers ₹10,000 from her Savings to her Checking account:

1. **Begin Transaction (T1)**

   * Read Savings balance (₹50,000)
   * Read Checking balance (₹5,000)

2. **Updates**

   * Savings → ₹40,000
   * Checking → ₹15,000

3. **Crash Scenario**

   * If the system crashes *after* debiting Savings but *before* crediting Checking, Bob’s money is “lost.”

4. **With Log-Based Recovery**

   * **Log record** before each change:

     ```
     [T1, Account=Savings, old=50000, new=40000]
     [T1, Account=Checking, old=5000,  new=15000]
     ```
   * On restart:

     * **Undo** any uncommitted debits/credits
     * **Redo** committed ones
   * → Alice’s ₹10,000 is either fully moved or not moved at all.

---

## 2. SQL-Backed Log Table Example 🖥️

```sql
-- 1. Log table schema
CREATE TABLE txn_log (
  log_id      SERIAL   PRIMARY KEY,
  txn_id      VARCHAR(20),
  table_name  VARCHAR(50),
  pk_value    VARCHAR(50),
  col_name    VARCHAR(50),
  old_value   TEXT,
  new_value   TEXT,
  log_time    TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  status      CHAR(1)  -- 'U' = uncommitted, 'C' = committed
);

-- 2. Writing a log record BEFORE update
INSERT INTO txn_log(txn_id, table_name, pk_value, col_name, old_value, new_value, status)
VALUES ('T1', 'accounts', 'acct_123', 'balance', '50000', '40000', 'U');

-- 3. Applying the update
UPDATE accounts
SET balance = 40000
WHERE account_id = 'acct_123';

-- 4. Marking commit
UPDATE txn_log
SET status = 'C'
WHERE txn_id = 'T1';
```

| Step | Action                           | SQL Command                   |
| ---- | -------------------------------- | ----------------------------- |
| 1    | Log “old → new” (uncommitted)    | `INSERT … status='U'`         |
| 2    | Apply change to `accounts` table | `UPDATE accounts …`           |
| 3    | Mark transaction as committed    | `UPDATE txn_log … status='C'` |

---

## 3. Implementation Pseudocode 🖋️

```pseudocode
function BEGIN_TRANSACTION(txn):
    txn.log_pointer = END_OF_LOG

function LOG_AND_UPDATE(txn, table, pk, col, new_val):
    old_val = READ(table, pk, col)
    // 1. Write log record (old/new) to stable storage
    WRITE_LOG(txn.id, table, pk, col, old_val, new_val, status='U')
    FORCE_LOG_TO_DISK()
    // 2. Apply the update immediately
    WRITE(table, pk, col, new_val)

function COMMIT(txn):
    // 3. Mark all this txn’s log entries as committed
    FOR each record r WHERE r.txn_id == txn.id:
        r.status = 'C'
    FORCE_LOG_TO_DISK()
    // durable now!

function RECOVER():
    // Phase 1: Undo uncommitted
    FOR log_record IN LOG backward:
        IF log_record.status == 'U':
            WRITE(log_record.table, log_record.pk, log_record.col, log_record.old_value)

    // Phase 2: Redo committed
    FOR log_record IN LOG forward:
        IF log_record.status == 'C':
            WRITE(log_record.table, log_record.pk, log_record.col, log_record.new_value)
```

```ascii
Recovery →
┌──────────┐   ┌──────────────┐   ┌───────────┐
│ Read Log │──▶ Undo Phase   │──▶ Redo Phase │──▶ Done
└──────────┘   └──────────────┘   └───────────┘
```

---

⭐️ **Summary**

* **Real-life**: ensures your ₹10,000 isn’t half-lost.
* **SQL log**: simple table + INSERT/UPDATE pattern.
* **Pseudocode**: clear “log → update → commit → recover” flow.

Let me know if you’d like to drill into any one of these in more depth!
---
Below is an in-depth dive into all three aspects—🥇 the real-life banking scenario, 🥈 an expanded SQL log-table implementation, and 🥉 a detailed recovery pseudocode framework.

---

## A. Real-Life Banking Example: ₹10,000 Transfer 🚀

### 1. Setup

* **Tables**

  ```sql
  CREATE TABLE accounts (
    account_id   VARCHAR(20) PRIMARY KEY,
    holder_name  VARCHAR(100),
    balance      NUMERIC(12,2)
  );
  ```

* **Initial State**

  | account\_id | holder\_name |  balance |
  | ----------: | ------------ | -------: |
  |      SAV001 | Alice        | 50000.00 |
  |      CHK002 | Alice        |  5000.00 |

* **Transaction T1**: Move ₹10,000 from SAV001 → CHK002

### 2. Step-by-Step Timeline

```ascii
Time →
┌─────────┐           ┌───────────────┐           ┌─────────────┐
│ T1 START│           │  CRASH?!?     │           │ RECOVERY    │
└─────────┘           └───────────────┘           └─────────────┘
    │                        │                           │
    │ 1. Log “old→new” SAV   │                           │
    │ ─────────────────────→ │                           │
    │                        │                           │
    │ 2. Debit SAV balance   │                           │
    │ ─────────────────────→ │                           │
    │                        │                           │
    │ 3. Log “old→new” CHK   │                           │
    │ ─────────────────────→ │    CRASH before commit    │
    │                        │ ◀───────────────────────── │
    │ 4. Credit CHK balance  │                           │
    │ ─────────────────────→ │                           │
    │                        │                           │
    │ 5. COMMIT marker       │                           │
    │ ─────────────────────→ │                           │
```

* **Crash Points & Recovery**

  1. **Before any log** → No evidence of T1 → *do nothing*.
  2. **After first log only** (debit-logged but not applied) → *undo* via old-value.
  3. **After debit applied but before credit log** → *undo* the debit.
  4. **After both logs, before credit apply** → *redo* credit, *undo* debit? *Actually*, since commit hasn’t occurred, we treat as uncommitted → *undo* both.
  5. **After credit applied but before commit marker** → both updates applied but uncommitted → *undo* both.
  6. **After commit marker** → fully committed → *redo* any missing writes.

### 3. Recovery Actions

* **UNDO phase**: scan logs backwards, for each **uncommitted** entry, write `old_value` back.
* **REDO phase**: scan logs forwards, for each **committed** entry, ensure `new_value` is in place.

---

## B. Expanded SQL-Backed Log Table 🛠️

### 1. Enhanced Log Schema

```sql
CREATE TABLE txn_log (
  lsn          BIGSERIAL   PRIMARY KEY,   -- log sequence number
  txn_id       VARCHAR(20),
  table_name   VARCHAR(50),
  pk_value     VARCHAR(50),
  col_name     VARCHAR(50),
  old_value    TEXT,
  new_value    TEXT,
  timestamp    TIMESTAMP   DEFAULT NOW(),
  status       CHAR(1),     -- 'U'=uncommitted, 'C'=committed
  prev_lsn     BIGINT       -- pointer to previous log in this txn
);
```

* **LSN & prev\_lsn** form a *linked list* per transaction, simplifying grouped undo/redo.
* **status** flips from `U` → `C` at commit.

### 2. Trigger-Based Logging

```sql
-- Example for accounts.balance
CREATE FUNCTION log_balance_change() RETURNS TRIGGER AS $$
BEGIN
  INSERT INTO txn_log(txn_id, table_name, pk_value, col_name, old_value, new_value, status, prev_lsn)
  VALUES (
    current_setting('app.txn_id'),
    TG_TABLE_NAME,
    NEW.account_id,
    'balance',
    OLD.balance::TEXT,
    NEW.balance::TEXT,
    'U',
    (SELECT MAX(lsn) FROM txn_log WHERE txn_id = current_setting('app.txn_id'))
  );
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_log_balance
  BEFORE UPDATE ON accounts
  FOR EACH ROW EXECUTE FUNCTION log_balance_change();
```

* **`current_setting('app.txn_id')`** holds the active transaction ID (set at `BEGIN`).

### 3. Recovery via SQL

```sql
-- 1) Undo uncommitted
UPDATE accounts AS a
SET balance = l.old_value::NUMERIC
FROM txn_log AS l
WHERE l.status = 'U'
  AND l.table_name = 'accounts'
  AND a.account_id = l.pk_value;

-- 2) Redo committed
UPDATE accounts AS a
SET balance = l.new_value::NUMERIC
FROM txn_log AS l
WHERE l.status = 'C'
  AND l.table_name = 'accounts'
  AND a.account_id = l.pk_value;
```

| Phase | Query Focus                       |
| ----: | --------------------------------- |
|  UNDO | `status='U'` & use **old\_value** |
|  REDO | `status='C'` & use **new\_value** |

---

## C. Detailed Recovery Pseudocode Framework 🔧

Below is a more complete **Recovery Manager** with **Checkpoints** and **Crash Detection**.

```pseudocode
CLASS RecoveryManager:
  log             ← []           // persistent log file
  dirty_pages     ← set()        // pages modified in buffer
  txn_table       ← {}           // txn_id → status

  function begin_transaction(txn_id):
    txn_table[txn_id] = 'ACTIVE'

  function write(txn_id, table, pk, col, new_val):
    old_val = BufferPool.read(table, pk, col)
    // 1) Write-Ahead Log (WAL)
    entry = LogEntry(lsn=log.nextLSN(),
                     txn_id=txn_id,
                     table=table, pk=pk,
                     col=col,
                     old_value=old_val,
                     new_value=new_val,
                     status='U',
                     prev_lsn=lastLSN(txn_id))
    log.append(entry)
    log.flush()                // ensure durable
    // 2) Apply to buffer (in-memory)
    BufferPool.write(table, pk, col, new_val)
    dirty_pages.add((table, pk))

  function commit(txn_id):
    // mark commit log record
    entry = LogEntry(lsn=log.nextLSN(),
                     txn_id=txn_id,
                     type='COMMIT',
                     status='C',
                     prev_lsn=lastLSN(txn_id))
    log.append(entry)
    log.flush()
    txn_table[txn_id] = 'COMMITTED'

  function checkpoint():
    // write all dirty pages to disk
    for page in dirty_pages:
      Disk.write(page)
    dirty_pages.clear()
    // write checkpoint record
    entry = LogEntry(lsn=log.nextLSN(),
                     type='CHECKPOINT',
                     dirty_pages=list(dirty_pages))
    log.append(entry)
    log.flush()

  function recover():
    // 1) Read last checkpoint to find start point
    start_lsn = log.findLast('CHECKPOINT').lsn
    // 2) REDO from start_lsn
    for entry in log.entries_from(start_lsn):
      if entry.type == 'UPDATE' and (txn_table[entry.txn_id] == 'COMMITTED' or entry.status=='C'):
        Disk.write((entry.table, entry.pk), entry.col, entry.new_value)
    // 3) UNDO all uncommitted
    for entry in log.backward_from_end():
      if entry.type == 'UPDATE' and txn_table[entry.txn_id] != 'COMMITTED':
        Disk.write((entry.table, entry.pk), entry.col, entry.old_value)
```

```ascii
Checkpoints & Recovery →
┌───┐   ┌───────────┐   ┌──────────┐   ┌─────────┐
│CL#1│──▶ REDO from╌┼──▶ apply   │   │ UNDO    │
└───┘   └───────────┘   └──────────┘   └─────────┘
```

* **Write-Ahead Logging (WAL)**: never write data to disk before its log record is durable.
* **Checkpoints** prune the log & bound recovery time.
* **Two-Phase Recovery**:

  1. **Redo** everything *committed* since last checkpoint.
  2. **Undo** any *active or aborted* transactions by rolling back their uncommitted updates.

---

🎯 **With these three views**—a concrete banking scenario, a production-style SQL log table, and a robust recovery manager—you have a full 360° on atomicity & durability in action. Let me know which part you’d like to drill into further!
