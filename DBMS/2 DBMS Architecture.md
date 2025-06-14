
## 📚 LEC-2: DBMS Architecture

---

### 1️⃣ View of Data (Three Schema Architecture)

#### 🧠 Purpose of DBMS:

* The major purpose of DBMS is to provide users with an abstract view of the data. That is, the system hides certain details of how the data is stored and maintained.
* To simplify user interaction with the system, abstraction is applied through several levels of abstraction.
* The main objective of three level architecture is to enable multiple users to access the same data with a personalized view while storing the underlying data only once.

```
                  DBMS (Centralized DB)
           +------------------------------+
           |     +------------------+     |
           |     |       DB         |     |
           |     |  (Customer Info) |     |
           |     +------------------+     |
           +------------------------------+
                    /     |        \
                   /      |         \
                  /       |          \
                 /        |           \
                /         |            \
+-------------------+ +------------------------+ +------------------+
| Logistics Dept.   | | Customer Service Center| |  Internal Dept.  |
| (User 3)          | | (User 1)               | |  (User 2)        |
|                   | |                        | |                  |
|  Accesses:        | |  Accesses:             | |  Depends         |
|  - Name           | |  - Name                | |                  |
|  - Address        | |  - Address             | |                  |
|  - Phone No.      | |  - Phone No.           | |                  |
|                   | |  - Product Bought      | |                  |
+-------------------+ +------------------------+ +------------------+

Customer Info in DB includes:
- Name
- Address
- Phone No.
- Likes/Dislikes
- Age
- Credit Card (CC)
- Debit Card (DC) / UPI
- Product Bought

```

---

#### 🔽 a. Physical Level / Internal Level

* The **lowest level of abstraction** describes how the data are stored.
* Low-level data structures used.
* It has **Physical schema** which describes physical storage structure of DB.
* Blueprint for Human Understanding
* Talks about:

  * Storage allocation (e.g., N-ary tree 🌳)
  * Data compression & encryption 🔐
* 🎯 **Goal**: We must define algorithms that allow efficient access to data.

---

#### 🧩 b. Logical Level / Conceptual Level

* The **conceptual schema** describes the design of a database at the conceptual level.
* Describes **what data are stored** in DB and what **relationships** exist among those data.
* User at logical level does not need to be aware about physical-level structures.
* **DBA**, who must decide what information to keep in the DB use the logical level of abstraction.
* 🎯 **Goal**: Ease to use.

---

#### 👁️‍🗨️ c. View Level / External Level

* **Highest level of abstraction** aims to simplify users’ interaction with the system by providing **different view to different end-user**.
* Each **view schema** describes the database part that a particular user group is interested in and hides the remaining database from that user group.
* At the external level, a database contains several schemas that are sometimes called **subschemas**.
* The **subschema** is used to describe the different view of the database.
* Views also provide a **security mechanism** to prevent users from accessing certain parts of DB.

---

#### 🧱 Table: Three-Schema Architecture Summary

| Level           | Description                                   | Goal/Benefit                   | Managed By       |
| --------------- | --------------------------------------------- | ------------------------------ | ---------------- |
| Physical        | Low-level storage (N-ary trees, compression)  | Efficient storage access       | DBMS             |
| Logical         | Conceptual structure (schemas, relationships) | Logical organization & queries | DBA              |
| View (External) | User-specific views, hides other data         | Security and abstraction       | Application/User |

---
### 📌 Three-Level Schema Architecture (ANSI/SPARC model)

```
       External Level             External Level
        +-----------+            +-----------+
        | External  |            | External  |
        |  Schema   |            |  Schema   |
        +-----------+            +-----------+
             \                        /
              \                      /
     External / Conceptual Mapping
              \                    /
             +--------------------+
             |  Conceptual Level  |
             | Conceptual Schema  |
             +--------------------+
                      |
         Conceptual / Internal Mapping
                      |
             +----------------+
             |  Internal      |
             |    Level       |
             | InternalSchema |
             +----------------+
                      |
                  +-------+
                  |Database|
                  +-------+
```
---

### 2️⃣ Instances and Schemas

* The collection of actual information stored in the DB at a particular moment is called an **instance** of DB.
* Data Snapshot of DB,eg: data @12:35:35 04 07 2025.
```
                * Instance of DB example  *
+---------------------------------------------+
|                   Student                   |
+-----+--------+--------+--------+------------+
| Sr# |  Name  |   Ph   | Address|   Batch    |
+-----+--------+--------+--------+------------+
|  1  |  xyz   |   xx   |   xx   |     xx     |
|  2  |  abc   |   xx   |   xx   |     xx     |
|  3  |        |        |        |            |
+-----+--------+--------+--------+------------+

Time: 12:00 AM
State of DB? → 2 rows, 2 data points

Next 12:00 AM → 3 students

```
* The overall design of the DB is called the **DB schema**.
* Schema is **structural description** of data. Schema **doesn’t change frequently**. Data **may change frequently**.
* DB schema corresponds to the **variable declarations (along with type)** in a program.
*  
#### 📦 Types of Schemas:

* **Physical**, **Logical**, and **several view schemas** called **subschemas**.
* Logical schema is **most important** in terms of its effect on application programs, as programmers construct apps by using logical schema.
* DB Schema Term = Logical Schema = overall design of db
* **Physical data independence**: Physical schema change should **not affect logical schema/application programs**.

---

### 3️⃣ Data Models

* Provides a way to **describe the design** of a DB at logical level.
* Underlying the structure of the DB is the **Data Model**; a collection of **conceptual tools** for describing:

  * Data 🧮
  * Data relationships 🔗
  * Data semantics 🧠
  * Consistency constraints ✅

#### 🧰 Examples:

* **ER model**
* **Relational model**
* **Object-oriented model**
* **Object-relational model** = **Relational model** + **Object-oriented model**

---

### 4️⃣ Database Languages

* **Data Definition Language (DDL)** to specify the database schema.
* **Data Manipulation Language (DML)** to express database queries and updates.
* Practically, both language features are present in a single DB language, e.g., **SQL**.

#### 📌 DDL

* We specify **consistency constraints**, which must be checked every time DB is updated.

#### ✍️ DML

Data manipulation involves:

1. Retrieval of information stored in DB 🔍
2. Insertion of new information into DB ➕
3. Deletion of information from the DB ❌
4. Updating existing information stored in DB 🔁

* **Query language**, a part of DML to specify statements requesting the retrieval of information.

```
* Database Language *

DDL ➝ 
    CREATE TABLE students (
        stu_ID   INT,
        Name     VARCHAR(50),
        add      VARCHAR(90),
        ph       INT
    );

DML ➝ 
    SELECT * FROM students;

```
---

### 5️⃣ How is Database Accessed from Application Programs?

* Apps (written in **host languages**, e.g., C/C++, Java) interact with DB.
* Example: Banking system’s module generating payrolls access DB by executing **DML statements** from the host language.
* 2 Imcompatible stuff cross-communicate form a special interface build for them called Application Programming Interface

#### 🔗 APIs:

* **ODBC** (Open Database Connectivity) – Microsoft “C”
* **JDBC** (Java Database Connectivity) – Java
```java
// Imports (Spring + JDBC + Util)
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.dao.DataAccessException;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.dao.IncorrectResultSizeDataAccessException;
import org.springframework.jdbc.core.namedparam.MapSqlParameterSource;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.jdbc.support.GeneratedKeyHolder;
import org.springframework.jdbc.support.KeyHolder;

import java.util.List;

public class CandidateDAOImpl extends AbstractDAO implements CandidateDAO {

    private static final Logger logger = LoggerFactory.getLogger(CandidateDAOImpl.class);

    // SQL for analytics
    private static final String SQL_TALENT_PARTNER_ANALYTICS = 
        "SELECT TALENT_PARTNER, count(*) as total, " +
        "sum(case when status = 'SELECTED' then 1 else 0 end)";

    public Integer add(CandidateDTO candidateDTO) {
        try {
            MapSqlParameterSource namedParameters = new MapSqlParameterSource();
            namedParameters.addValue("name", candidateDTO.getName());
            namedParameters.addValue("phone", candidateDTO.getPhone());
            namedParameters.addValue("emailId", candidateDTO.getEmailId());
            namedParameters.addValue("driveId", candidateDTO.getDriveId());
            namedParameters.addValue("resume", candidateDTO.getResumePath());
            namedParameters.addValue("status", candidateDTO.getStatus());
            namedParameters.addValue("createdUserId", candidateDTO.getCreatedUserId());

            KeyHolder keyHolder = new GeneratedKeyHolder();

            int affectedRowCount = this.namedParameterJdbcTemplate.update(
                "INSERT INTO CANDIDATE " +
                "(NAME, PHONE, EMAIL_ID, RESUME_PATH, DRIVE_ID, STATUS, CREATED_USER_ID) " +
                "VALUES (:name, :phone, :emailId, :resume, :driveId, :status, :createdUserId)",
                namedParameters,
                keyHolder
            );

            if (affectedRowCount == 1) {
                return keyHolder.getKey().intValue();
            }

        } catch (Exception e) {
            logger.error("Error in adding candidate", e);
        }

        return null;
    }
}
```
---

### 6️⃣ Database Administrator (DBA)

* A person who has **central control** of both the data and the programs that access those data.

#### 🛠️ Functions of DBA:

1. Schema Definition 📐
2. Storage structure and access methods 💾
3. Schema and physical organization modifications 🔧
4. Authorization control 🔐
5. Routine maintenance 🔄

   * Periodic backups 💽
   * Security patches 🛡️
   * Any upgrades ⬆️

---

### 7️⃣ DBMS Application Architectures

> Client machines, on which remote DB users work, and server machines on which DB system runs.

#### 🖥️ a. T1 Architecture

* The client, server & DB all present on the **same machine**.
* eg : localhost app

---

#### 🌐 b. T2 Architecture

* App is partitioned into **2 components**.
* Client machine invokes DB system functionality at server end through **query language statements**.
* API standards like **ODBC & JDBC** are used to interact between client and server.
* eg: flask connect to mongodbURI

---

#### 🧠 c. T3 Architecture

* App is partitioned into **3 logical components**.
* Client machine is just a **frontend** and doesn’t contain any direct DB calls.
* Client machine communicates with **App server**, and App server communicates with **DB system** to access data.
* **Business logic** (what action to take) resides in App server itself.
* Backend can handle vulnerability before coming to DB :0
* Layered Security :0
* T3 architectures are best for **WWW applications**.
* eg: MongoDBURI + Backend at digital ocean + frontend at verel

##### 🌟 Advantages:

1. **Scalability** due to distributed application servers 📈
2. **Data integrity** – App server as middle layer minimizes data corruption ✅
3. **Security** – Client can’t directly access DB 🔐

---

#### 🧾 Architecture Comparison Table:

| Feature        | T1 Architecture | T2 Architecture          | T3 Architecture                          |
| -------------- | --------------- | ------------------------ | ---------------------------------------- |
| Layers         | Single-tier     | Two-tier (Client-Server) | Three-tier (Client–App Server–DB Server) |
| Client Role    | All components  | UI + some DB logic       | UI only                                  |
| Business Logic | Local           | Partial (Client-side)    | Fully in App Server                      |
| Performance    | Low scalability | Medium                   | High scalability                         |
| Security       | Weak            | Moderate                 | Strong (isolated DB)                     |
| Best For       | Local apps      | Small client-server apps | Web-based or enterprise apps 🌐          |

---

### 📌 Two-tier and Three-tier Architectures

```
a. Two-tier architecture                  b. Three-tier architecture

      +--------+                                +--------+
      |  user  |                                |  user  |           Client
      +--------+                                +--------+
          |                                         |
      +-------------+                         +------------------+
      | application |                         | application client|
      +-------------+                         +------------------+
          |                                         |
      ----------- Network ------------         ----------- Network -----------
          |                                         |
  +-------------------+                     +-------------------+    Server
  |  database system  |                     | application server|
  +-------------------+                     +-------------------+
                                            |  database system  |
                                            +-------------------+
```

---