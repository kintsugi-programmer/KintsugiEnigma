
## 📚 **Partitioning & Sharding in DBMS (DB Optimisation)**

---

### 🔍 1. Introduction

> A big problem can be solved easily when it is chopped into several smaller sub-problems.
> That is what the **partitioning technique** does. It divides a big database containing data metrics and indexes into smaller and handy slices of data called **partitions**.

* The **partitioned tables** are directly used by SQL queries **without any alteration**.
* Once the database is partitioned, the **Data Definition Language (DDL)** can easily work on the smaller partitioned slices instead of handling the giant database altogether.
* This is how partitioning cuts down the problems in managing large database tables.

---

### ⚙️ 2. What is Partitioning?

> Partitioning is the technique used to **divide stored database objects** into **separate servers**.

* ✅ Increases **performance**
* ✅ Improves **controllability**
* ✅ Enables handling of **huge data** optimally
* 🚀 Useful when **horizontally scaling** machines or servers
* ❗ Challenges arise when maintaining relations in **relational databases**

---

### 🧱 3. Vertical Partitioning

> 📏 **Slicing relation vertically** (i.e. column-wise)

* Each server holds a **subset of columns**
* To get **complete tuples**, access to **multiple servers** is needed

```sql
-- Example: Vertical Partitioning
-- Table: Employee(id, name, dept, salary)

-- Server A
CREATE TABLE Employee_Info (id INT, name VARCHAR(100));

-- Server B
CREATE TABLE Employee_Job (id INT, dept VARCHAR(50), salary INT);
```

---

### 📊 4. Horizontal Partitioning

> 📏 **Slicing relation horizontally** (i.e. row-wise)

* Each partition stores **independent chunks of tuples**
* Usually used in **sharding**

```sql
-- Example: Horizontal Partitioning
-- Partitioning Employees by Region

-- Server A
SELECT * FROM Employee WHERE region = 'North';

-- Server B
SELECT * FROM Employee WHERE region = 'South';
```

---

### 📅 5. When is Partitioning Applied?

* When dataset becomes **very large** and unmanageable
* When **number of requests** increase and **single DB access becomes slow**, causing high system response time

---

### ✅ 6. Advantages of Partitioning

| Advantage         | Benefit Description                                                  |
| ----------------- | -------------------------------------------------------------------- |
| 🔄 Parallelism    | Query execution in parallel on different partitions                  |
| 🌐 Availability   | If one partition fails, others can still operate                     |
| 🚀 Performance    | Smaller partitions = faster queries                                  |
| 🛠 Manageability  | Easier schema changes, backups, and restores                         |
| 💰 Cost Reduction | Vertical scaling is expensive; partitioning helps scale horizontally |

---

### 🌍 7. Distributed Database

* A **single logical database** that is spread across multiple locations (servers)
* Logically interconnected via **network**
* Product of DB optimization techniques like:

  * ✅ Clustering
  * ✅ Partitioning
  * ✅ Sharding

> ❓ Why is this needed?
> 👉 Refer **Point 5** (Large datasets, high load, response time)

---

### 🧩 8. Sharding

> Sharding is a **technique to implement Horizontal Partitioning**

#### 📌 Core Idea:

Instead of keeping all data on **one DB instance**, split it up and introduce a **Routing Layer**
This layer forwards requests to the **correct DB instance** based on shard key

#### ✅ Pros

| Feature         | Description                                     |
| --------------- | ----------------------------------------------- |
| 📈 Scalability  | Can handle massive growth by adding more shards |
| 🟢 Availability | Failure in one shard doesn’t affect others      |

#### ❌ Cons

| Drawback                 | Explanation                                          |
| ------------------------ | ---------------------------------------------------- |
| ⚠️ Complexity            | Requires partition mapping, routing logic, etc.      |
| 🧩 Re-Sharding           | When data becomes imbalanced, redistribution is hard |
| ❓ Scatter-Gather Problem | Not suited for analytical queries due to data spread |

---

#### 🧪 Code Illustration for Shard Routing

```python
## Python pseudo-code example of sharding router

def route_request(user_id):
    shard_id = user_id % 4  ## 4 shards
    return f"DB_Instance_{shard_id}"

print(route_request(123))  ## routes to DB_Instance_3
```

---

> ✅ **Tip**: Always choose the partitioning technique based on the use-case — whether transactional, analytical, or hybrid!

