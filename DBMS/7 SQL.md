## SQL

### 1. SQL: Structured Query Language 🔍
- SQL: Structured Query Language, used to access and manipulate data.  

### 2. CRUD Operations 🛠️
SQL uses **CRUD** operations to communicate with the DB:
1. **CREATE**: execute `INSERT` statements to insert new tuple into the relation.  
2. **READ**: Read data already in the relations.  
3. **UPDATE**: Modify already inserted data in the relation.  
4. **DELETE**: Delete specific data point/tuple/row or multiple rows.  

### 3. SQL vs Database ❓
- SQL is _not_ a DB; it is a **query language**.  

### 4. What is RDBMS? (Relational Database Management System) 🗄️
1. Software that enables us to implement the designed relational model.  
2. **Examples**: MySQL, MS SQL, Oracle, IBM, etc.  
3. **Table/Relation** is the simplest form of data storage object in an RDB.  
4. MySQL is open-source RDBMS, and it uses SQL for all CRUD operations.  
5. MySQL uses a **client-server model**, where the client (CLI or frontend) uses services provided by the MySQL server.  
6. **Difference between SQL and MySQL**  
   - SQL is a **Structured Query Language** used to perform CRUD operations in an RDB,  
   - while MySQL is an **RDBMS** used to store, manage, and administrate databases (provided by itself) using SQL.  

---

### 5. SQL DATA TYPES 📊  
_Reference: [w3schools.com/sql/sql_datatypes.asp](https://www.w3schools.com/sql/sql_datatypes.asp)_

1. In SQL DB, data is stored in the form of **tables**.  
2. Data can be of different **types**, like `INT`, `CHAR`, etc.  

| **DATATYPE**   | **Description**                                                         |
|----------------|-------------------------------------------------------------------------|
| `CHAR`         | string(0-255), size = (0, 255], e.g., `CHAR(251)`                       |
| `VARCHAR`      | string(0-255)                                                           |
| `TINYTEXT`     | String(0-255)                                                           |
| `TEXT`         | string(0-65535)                                                         |
| `BLOB`         | string(0-65535)                                                         |
| `MEDIUMTEXT`   | string(0-16777215)                                                      |
| `MEDIUMBLOB`   | string(0-16777215)                                                      |
| `LONGTEXT`     | string(0-4294967295)                                                    |
| `LONGBLOB`     | string(0-4294967295)                                                    |
| `TINYINT`      | integer(-128 to 127)                                                    |
| `SMALLINT`     | integer(-32768 to 32767)                                                |
| `MEDIUMINT`    | integer(-8388608 to 8388607)                                            |
| `INT`          | integer(-2147483648 to 2147483647)                                      |
| `BIGINT`       | integer(-9223372036854775808 to 9223372036854775807)                    |
| `FLOAT`        | Decimal with precision up to 23 digits                                  |
| `DOUBLE`       | Decimal with precision 24 to 53 digits                                  |

**DATATYPE CodeHelp**

3. **Size hierarchy**: `TINY` < `SMALL` < `MEDIUM` < `INT` < `BIGINT`.  
4. Variable-length data types (e.g., `VARCHAR`) are better to use as they occupy space equal to the actual data size.  
5. Values can also be **unsigned**, e.g., `INT UNSIGNED`.  

---

### 6. Types of SQL Commands ⚙️

1. **DDL** (Data Definition Language): defining relation schema  
   - `CREATE`: create table, DB, view.  
   - `ALTER TABLE`: modify table structure (change datatype, add/remove columns).  
   - `DROP`: delete table, DB, view.  
   - `TRUNCATE`: remove all tuples from the table.  
   - `RENAME`: rename DB name, table name, column name, etc.  

2. **DRL/DQL** (Data Retrieval/Query Language): retrieve data from tables  
   - `SELECT`  

3. **DML** (Data Manipulation Language): perform modifications in the DB  
   - `INSERT`: insert data into a relation  
   - `UPDATE`: update relation data  
   - `DELETE`: delete row(s) from the relation  

4. **DCL** (Data Control Language): grant or revoke authorities from users  
   - `GRANT`: access privileges to the DB  
   - `REVOKE`: revoke user access privileges  

5. **TCL** (Transaction Control Language): manage transactions in the DB  
   - `START TRANSACTION`: begin a transaction  
   - `COMMIT`: apply all changes and end transaction  
   - `ROLLBACK`: discard changes and end transaction  
   - `SAVEPOINT`: mark a point within a transaction to roll back to  

---

### 7. Managing DB (DDL) 🗂️

1. **Create a DB**  
   ```sql
   CREATE DATABASE IF NOT EXISTS db_name;
    ```

2. **Use a DB**

   ```sql
   USE db_name;  -- choose which DB to execute subsequent commands on
   ```
3. **Drop a DB**

   ```sql
   DROP DATABASE IF EXISTS db_name;
   ```
4. **Show DBs**

   ```sql
   SHOW DATABASES;  -- list all DBs in the server
   ```
5. **Show Tables**

   ```sql
   SHOW TABLES;     -- list tables in the selected DB
   ```

---

### 8. Additional Data Types 📝

| **Type**    | **Format**                        |
| ----------- | --------------------------------- |
| `DECIMAL`   | Double stored as string           |
| `DATE`      | YYYY-MM-DD                        |
| `DATETIME`  | YYYY-MM-DD HH\:MM\:SS             |
| `TIMESTAMP` | YYYYMMDDHHMMSS                    |
| `TIME`      | HH\:MM\:SS                        |
| `ENUM`      | One of the preset values          |
| `SET`       | One or many of the preset values  |
| `BOOLEAN`   | 0/1                               |
| `BIT(n)`    | Store values in bits (n up to 64) |

---

### 9. DATA RETRIEVAL LANGUAGE (DRL) 🔍

1. **Syntax**:

   ```sql
   SELECT <column_list> FROM <table_name>;
   ```
2. **Execution order**: right to left.
3. **Can we use `SELECT` without `FROM`?**

   * Yes, using **DUAL** tables (dummy tables in MySQL).
   * Examples:

     ```sql
     SELECT 55 + 11;
     SELECT NOW();
     SELECT UCASE('hello');
     ```

#### 9.1 WHERE (Filtering) 🎯

```sql
SELECT * FROM customer WHERE age > 18;
```

#### 9.2 BETWEEN 📏

```sql
SELECT * FROM customer WHERE age BETWEEN 0 AND 100;
```

#### 9.3 IN (Set membership) 📝

```sql
SELECT * FROM officers
WHERE officer_name IN ('Lakshay','Maharana Pratap','Deepika');
```

#### 9.4 AND / OR / NOT 🔄

```sql
-- AND
SELECT * FROM table WHERE cond1 AND cond2;

-- OR
SELECT * FROM table WHERE cond1 OR cond2;

-- NOT
SELECT * FROM table WHERE col_name NOT IN (1,2,3,4);
```

#### 9.5 IS NULL ❓

```sql
SELECT * FROM customer WHERE prime_status IS NULL;
```

#### 9.6 Pattern Searching / Wildcard 🔍

* `%` = any number of characters (0 to n).
* `_` = exactly one character.

```sql
SELECT * FROM customer WHERE name LIKE '%p_';
```

#### 9.7 ORDER BY ⬆️⬇️

```sql
SELECT * FROM customer ORDER BY name DESC;  -- DESC or ASC
```

#### 9.8 GROUP BY & Aggregations 📊

```sql
SELECT country, COUNT(cust_id)
FROM customer
WHERE <cond>
GROUP BY country;
```

#### 9.9 DISTINCT 🌟

1. Find distinct values:

   ```sql
   SELECT DISTINCT(col_name) FROM table_name;
   ```
2. `GROUP BY` can also achieve the same:

   ```sql
   SELECT col_name
   FROM table
   GROUP BY col_name;
   ```


3\. SQL is smart enough to realize that if you use `GROUP BY` without aggregates, it means **DISTINCT**.

#### 9.10 HAVING 🎯

```sql
SELECT country, COUNT(cust_id)
FROM customer
GROUP BY country
HAVING COUNT(cust_id) > 50;
```

* **WHERE vs HAVING**

  * `WHERE`: filters rows before grouping.
  * `HAVING`: filters groups after grouping.

---

### 10. CONSTRAINTS (DDL) 🔒

1. **PRIMARY KEY**: NOT NULL, UNIQUE, one per table.
   Here’s a Example plain‐ASCII version of your `Customer` table DDL showing the two ways to declare the primary key:

    ```
      Option 1: Inline column definition
      ----------------------------------
      CREATE TABLE Customer (
        id         INT       PRIMARY KEY,
        branch_id  INT,
        first_name CHAR(50),
        last_name  CHAR(50),
        DOB        DATE,
        Gender     CHAR(6)
      );


      Option 2: Table‐level constraint
      --------------------------------
      CREATE TABLE Customer (
        id         INT,
        branch_id  INT,
        first_name CHAR(50),
        last_name  CHAR(50),
        DOB        DATE,
        Gender     CHAR(6),
        PRIMARY KEY (id)
      );
    ```

    Or, if you like a little “box” to visualize it:

    ```
      +-------------------------------+
      |          Customer             |
      +-------------------------------+
      | id         INT    ◉ PK        |
      | branch_id  INT                |
      | first_name CHAR(50)           |
      | last_name  CHAR(50)           |
      | DOB        DATE               |
      | Gender     CHAR(6)            |
      +-------------------------------+
    ```

    Choose **either** the inline `id INT PRIMARY KEY` **or** the separate `PRIMARY KEY (id)` at the bottom—both yield the same result.

2. **FOREIGN KEY**: refers to PK of another table.

   ```sql
   CREATE TABLE `order` (
     id INT PRIMARY KEY,
     delivery_date DATE,
     order_placed_date DATE,
     cust_id INT,
     FOREIGN KEY (cust_id) REFERENCES customer(id)
   );
   ```
3. **UNIQUE**: can be NULL, multiple per table.

   ```sql
   CREATE TABLE customer (
     ...,
     email VARCHAR(1024) UNIQUE,
     ...
   );
   ```
4. **CHECK**

   ```sql
   CREATE TABLE customer (
     ...,
     CONSTRAINT age_check CHECK (age > 12),
     ...
   );
   ```

   * `"age_check"` can be omitted; MySQL auto-generates constraint names.
     
5. **DEFAULT**: set default column value.

   ```sql
   CREATE TABLE account (
     ...,
     saving_rate DOUBLE NOT NULL DEFAULT 4.25,
     ...
   );
   ```
6. An attribute can be both PK and FK in a table.

---

### 11. ALTER OPERATIONS ✏️

1. **ADD**

   ```sql
   ALTER TABLE table_name
     ADD new_col_name datatype,
         new_col_name_2 datatype;
   ```
2. **MODIFY** (change datatype)

   ```sql
   ALTER TABLE customer MODIFY name CHAR(1024);
   ```
3. **CHANGE COLUMN** (rename & datatype)

   ```sql
   ALTER TABLE customer
     CHANGE COLUMN name customer_name VARCHAR(1024);
   ```
4. **DROP COLUMN**

   ```sql
   ALTER TABLE customer DROP COLUMN middle_name;
   ```
5. **RENAME TABLE**

   ```sql
   ALTER TABLE old_name RENAME TO new_name;
   ```

---

### 12. DATA MANIPULATION LANGUAGE (DML) ✍️

#### 12.1 INSERT

```sql
INSERT INTO table_name(col1, col2, col3)
VALUES (v1, v2, v3), (val1, val2, val3);
```

#### 12.2 UPDATE

```sql
UPDATE table_name
SET col1 = 1, col2 = 'abc'
WHERE id = 1;

-- Update multiple rows
UPDATE student
SET standard = standard + 1;
```

* **ON UPDATE CASCADE**: automatically update FK when PK changes.

#### 12.3 DELETE

```sql
DELETE FROM table_name WHERE id = 1;
DELETE FROM table_name;  -- delete all rows
```

* **DELETE CASCADE**

  ```sql
  CREATE TABLE `order` (
    order_id INT PRIMARY KEY,
    delivery_date DATE,
    cust_id INT,
    FOREIGN KEY(cust_id) REFERENCES customer(id) ON DELETE CASCADE
  );
  ```
* **ON DELETE SET NULL**

  ```sql
  CREATE TABLE `order` (
    order_id INT PRIMARY KEY,
    delivery_date DATE,
    cust_id INT,
    FOREIGN KEY(cust_id) REFERENCES customer(id) ON DELETE SET NULL
  );
  ```

#### 12.4 REPLACE

* Acts as `UPDATE` if PK exists, else `INSERT`.

  ```sql
  REPLACE INTO student (id, class) VALUES (4, 3);
  REPLACE INTO table_name SET col1 = val1, col2 = val2;
  ```

---

### 13. JOINING TABLES 🔗

---

**CROSS JOIN** (Cartesian product – every row in A paired with every row in B)

```
TableA      TableB      Resulting Pairs
+-----+     +-----+     +---------+
|  1  |     |  A  |     |  (1, A) |
+-----+     +-----+     |  (1, B) |
|  2  |     |  B  |     |  (1, C) |
+-----+     +-----+     |  (2, A) |
|  3  |     |  C  |     |  (2, B) |
+-----+     +-----+     |  (2, C) |
                      |  (3, A) |
                      |  (3, B) |
                      |  (3, C) |
                      +---------+
```

---

**FULL OUTER JOIN** (all rows from both tables)

```
       _________           _________
      /         \         /         \
     /           \_______/           \
     \           /       \           /
      \_________/         \_________/
        TABLE1               TABLE2

(shaded: entire circles – everything from TABLE1 ∪ TABLE2)
```

---

**RIGHT OUTER JOIN** (all rows from TABLE2, plus matches from TABLE1)

```
       _________           _________
      /         \         /#########\
     /           \_______/###########\
     \           /       \###########/
      \_________/         \#########/
        TABLE1        ###  TABLE2  ###

(shaded: right circle + overlap)
```

---

**LEFT OUTER JOIN** (all rows from TABLE1, plus matches from TABLE2)

```
       _________           _________
      /#########\         /         \
     /###########\_______/           \
     \###########/       \           /
      \#########/         \_________/
     ### TABLE1 ###      TABLE2

(shaded: left circle + overlap)
```

---

**INNER JOIN** (only the matching rows)

```
       _________           _________
      /         \         /         \
     /           \_______/           \
     \           /       \           /
      \_________/         \_________/
        TABLE1       ###  TABLE2  ###
             (only overlap shaded)

(shaded: only the intersection region)
```

1. **INNER JOIN**: returns rows with matching values in both tables.

   ```sql
   SELECT t1.col, t2.col
   FROM table1 AS t1
   INNER JOIN table2 AS t2
     ON t1.id = t2.id;
   ```
2. **Aliases** (AS): temporary names for tables/columns.

   ```sql
   SELECT col_name AS alias_name FROM table_name AS alias_name;
   ```

#### 13.1 OUTER JOIN

* **LEFT JOIN**: all rows from left + matched from right.
* **RIGHT JOIN**: all rows from right + matched from left.
* **FULL JOIN** (MySQL emulated via `LEFT UNION RIGHT`).
* **UNION ALL** to include duplicates.

#### 13.2 CROSS JOIN

* Cartesian product (rare).

  ```sql
  SELECT * FROM table1 CROSS JOIN table2;
  ```

#### 13.3 SELF JOIN

* Joining a table to itself.

  ```sql
  SELECT a.*, b.*
  FROM table AS a
  INNER JOIN table AS b
    ON a.id = b.id;
  ```

#### 13.4 Implicit Join

```sql
SELECT artist_name, album_name
FROM artist, album
WHERE artist.id = album.artist_id;
```

---

### 14. SET OPERATIONS ⚖️

* **UNION** (distinct):

  ```sql
  SELECT * FROM table1
  UNION
  SELECT * FROM table2;
  ```
* **INTERSECT** (common rows, emulated):

  ```sql
  SELECT DISTINCT col
  FROM table1
  INNER JOIN table2 USING (join_col);
  ```
* **MINUS/EXCEPT** (first not in second, emulated):

  ```sql
  SELECT col
  FROM table1
  LEFT JOIN table2 USING (id)
  WHERE table2.id IS NULL;
  ```

---

### 15. SUBQUERIES 🔄
```
           +--------------------------+        ← Parent Query
           |          QUERY           |
           |  +--------------------+  |
           |  |      SUBQUERY      |  |  ← Nested/Inner Query
           |  +--------------------+  |
           +--------------------------+

```
1. **Nested queries**: inner query drives the outer.
2. **Alternative to joins**.
3. Exists in three clauses:

   * **WHERE**

     ```sql
     SELECT * FROM table1
     WHERE col1 IN (SELECT col1 FROM table2);
     ```
   * **FROM**

     ```sql
     SELECT MAX(rating)
     FROM (
       SELECT * FROM movie WHERE country = 'India'
     ) AS temp;
     ```
   * **SELECT**

     ```sql
     SELECT
       (SELECT COUNT(*) FROM orders WHERE cust_id = c.id) AS order_count,
       c.name
     FROM customer AS c;
     ```
4. **Derived subquery**:

   ```sql
   SELECT t.*
   FROM (
     SELECT col_list FROM table WHERE cond
   ) AS new_table;
   ```
5. **Correlated subquery**: inner runs per outer row.
    ```sql
    SELECT column1, column2, ….
    FROM   table1 AS outer
    WHERE  column operator
          (
            SELECT column1, column2
            FROM   table2
            WHERE  expr1 = outer.expr2
          );
    ```
---

### 16. JOIN vs SET OPERATIONS Comparison 📑

```
+--------------------------------------+---------------------------------------------+
|               JOIN                 |             SET OPERATIONS                  |
+--------------------------------------+---------------------------------------------+
| Combines multiple tables based on   | Combination is the resulting set from two   |
| matching condition.                  | or more SELECT statements.                  |
| Column-wise combination.            | Row-wise combination.                       |
| Data types of two tables can be     | Data types of corresponding columns must    |
| different.                           | be the same.                                |
| Can generate both distinct or       | Generates distinct rows only.               |
| duplicate rows.                      |                                             |
| Number of selected columns may      | Number of selected columns must match       |
| vary between queries.                | across queries.                             |
| Combines results horizontally.      | Combines results vertically.                |
+--------------------------------------+---------------------------------------------+
```



---

### 17. MySQL VIEWS 🖥️

* A **view** is a virtual table defined by a query; it contains no data itself.
* **Create**:

  ```sql
  CREATE VIEW view_name AS
  SELECT columns FROM tables WHERE conditions;
  ```
* **Alter**:

  ```sql
  ALTER VIEW view_name AS
  SELECT ...
  FROM table WHERE ...;
  ```
* **Drop**:

  ```sql
  DROP VIEW IF EXISTS view_name;
  ```
* **Example**:

  ```sql
  CREATE VIEW Trainer AS
    SELECT c.course_name, c.trainer, t.email
    FROM courses AS c
    JOIN contact AS t
      ON c.id = t.id;
  ```

> **Note**: You can also import/export table schema from files (`.csv` or ` .json`).

