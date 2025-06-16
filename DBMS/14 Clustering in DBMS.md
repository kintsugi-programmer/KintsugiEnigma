
## 📚 Clustering in DBMS

---

### 🔗 1. What is Database Clustering?

* **Database Clustering (Replica-sets)** is the process of combining more than one server or instance connecting to a single database.
* Sometimes one server may not be adequate to manage:

  * The amount of data
  * The number of requests
* That is when a **Data Cluster** is needed.
* **Database clustering**, **SQL server clustering**, and **SQL clustering** are closely associated with **SQL** (the language used to manage the database information).

---

### 🔁 2. Replication

* **Replicate the same dataset on different servers**.

---

### ✅ 3. Advantages of Database Clustering

#### 🔸 1. Data Redundancy

* Clustering of databases helps with **data redundancy**, as we store the same data at **multiple servers**.
* ⚠️ *Note*: Don’t confuse this redundancy with **anomalies** due to data repetition.
* The redundancy **offered by clustering is intentional** and required for **synchronisation**.
* If any server **fails**, data is still **available** on other servers.

#### 🔸 2. Load Balancing

* **Scalability doesn’t come by default** in databases — clustering enables it.
* **Load balancing** distributes the workload across multiple servers in the cluster:

  * More users can be supported.
  * System handles **traffic spikes** efficiently.
  * Prevents a **single machine** from being overwhelmed.
* ✅ Results in **seamless scaling** and improved performance.
* ⚠️ Without load balancing, traffic slows down and may drop to zero.

#### 🔸 3. High Availability

* **Availability** = database can be accessed.
* **High availability** = database is available for a **maximum amount of time**.
* Depends on:

  * Number of transactions.
  * Frequency of analytics.
* With **clustering**:

  * Extremely high availability is achievable.
  * Load is distributed.
  * Extra machines act as backup in case of failures.
  * Database stays available even if a server goes down.

---

### ⚙️ 4. How Does Clustering Work?

* In **cluster architecture**, all requests are **split** across multiple computers.
* An individual user request is **executed collaboratively** by several systems.
* 🧠 Clustering leverages:

  * **Load balancing**
  * **High availability**
* If **one node fails**, another **takes over** the request.
* ✅ Result: Very low risk of **complete system failure**.

---

### 📊 Comparison Table: Traditional vs Clustered DBMS

| Feature         | Traditional DBMS                  | Clustered DBMS          |
| --------------- | --------------------------------- | ----------------------- |
| Scalability     | Limited                           | High with load balancer |
| Availability    | Limited (single point of failure) | High (redundant nodes)  |
| Data Redundancy | Minimal                           | Intentional & Synced    |
| Fault Tolerance | Low                               | High                    |
| Performance     | Degrades under load               | Stable under high load  |

---

### 💡 Takeaway

> Database clustering is a powerful technique to **scale**, **secure**, and **stabilize** large-scale data systems, ensuring **redundancy**, **resilience**, and **performance**.

---
