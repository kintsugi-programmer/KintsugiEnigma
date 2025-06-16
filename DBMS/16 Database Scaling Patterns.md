
## 📦 **Database Scaling Patterns**
```
       +---------+             +---------+ +---------+ +---------+
       |         |             |         | |         | |         |
       |   DB    |  -------->  |   DB    | |   DB    | |   DB    |
       |         |             |         | |         | |         |
       +---------+             +---------+ +---------+ +---------+
```
### 🚀 Step-by-Step Scaling

🔧 **What will you learn?**

* ✅ Step by Step manner, when to choose which Scaling option.
* ✅ Which Scaling option is feasible practically at the moment.

---

### 🧪 A Case Study – Cab Booking App

| 🚕 Stage | Details                                                                                                    |
| -------- | ---------------------------------------------------------------------------------------------------------- |
| Startup  | Tiny startup.                                                                                              |
| Users    | \~10 customers onboard.                                                                                    |
| Infra    | A single small machine DB stores all customers, trips, locations, booking data, and customer trip history. |
| Usage    | \~1 trip booking in 5 mins.                                                                                |

---

### 🔥 Your App Becoming Famous, but…

#### ❗ The PROBLEM Begins

* 📈 Requests scales up to 30 bookings per minute.
* 🧠 Your tiny DB system has started performing poorly.
* ⏳ API latency has increased a lot.
* 🔒 Transactions facing **Deadlock**, **Starvation**, and **frequent failure**.
* 🐢 Sluggish App experience.
* 😞 Customer dis-satisfaction.

---

### ✅ Is there any solution?

* ⚙️ We have to apply some kind of performance optimisation measures.
* 📊 We might have to scale our system going forward.

---

## 🧩 Pattern 1

### 🔍 Query Optimisation & Connection Pool Implementation

* 📥 Cache frequently used non-dynamic data like booking history, payment history, user profiles etc.
* 📀 Introduce **Database Redundancy**. *(Or maybe use NoSQL)*
* 🔁 Use **connection pool** libraries to cache DB connections.
* 🧵 Multiple application threads can use same DB connection.
* 🟢 Good optimisations as of now.
* 🌆 Scaled the business to one more city, and now getting \~100 booking per minute.

---

## 🧱 Pattern 2

### ⬆️ Vertical Scaling or Scale-up

* 🔧 Upgrading our initial tiny machine.
* 📈 RAM by 2x and SSD by 3x etc.
* 💰 Scale-up is pocket-friendly till a point only.
* ⚠️ More you scale up, cost increases **exponentially**.
* 🟢 Good Optimisation as of now.
* 🌆 Business is growing, scaled to 3 more cities, now getting **300 booking per minute**.

---

## 🪄 Pattern 3

### 🔄 Command Query Responsibility Segregation (CQRS)

* ❌ Scaled-up machine can't handle all read/write requests.
* 📑 Separate read/write operations physical machine-wise.
* 🖥️ 2 more machines as **replica** to the primary machine.
* 📖 All **read queries to replicas**.
* ✍️ All **write queries to primary**.
* 🌆 Business is growing, scaled to 2 more cities.
* 🚨 Primary is not able to handle all write requests.
* 🕒 Lag between primary and replica is impacting user experience.

---

## 🧬 Pattern 4

### 🧠 Multi Primary Replication

* 🤔 Why not distribute write request to replica also?
* 🖥️ All machines can work as **primary & replica**.
* 🔁 Multi-primary configuration is a **logical circular ring**.
* ✍️ Write data to any node.
* 📖 Read data from any node that replies to the broadcast first.
* 🌍 Scaled to 5 more cities — system is in **pain again** (\~50 req/s).

---

## 🧳 Pattern 5

### 📂 Partitioning of Data by Functionality

* 📍 What about separating the **location tables** in separate DB schema?
* 💽 What about putting that DB in separate machines with primary-replica or multi-primary configuration?
* 🧱 Different DB can host data categorised by different **functionality**.
* 🧠 **Backend or application layer** has to take responsibility to join the results.
* 🌏 Planning to expand your business to **another country**.

---

## 🌐 Pattern 6

### 📤 Horizontal Scaling or Scale-out

* ⚒️ **Sharding** - multiple shards.
* 💻 Allocate **50 machines** – all having same DB schema – each machine holds **a part of data**.
* 📌 Locality of data should be there.
* 🧑‍🤝‍🧑 Each machine can have their own replicas – used in **failure recovery**.
* 🧠 Sharding is generally hard to apply.
* 📈 But “**No Pain, No Gain**”
* 🌍 Scaling the business across **continents**.

---

## 🏢 Pattern 7

### 🌎 Data Centre Wise Partition

* 🛰️ Requests travelling across continents are having **high latency**.
* 🏬 What about distributing traffic across **data centres**?
* 🌐 Data centres across continents.
* 🔄 Enable **cross data centre replication** for **disaster recovery**.
* 🟢 This always maintains **Availability** of your system.
* 💹 Now, Plan for an **IPO** \:p

---

### 📊 Summary Table

| Pattern No. | Name                            | Key Idea                     | Scalability  | Cost            |
| ----------- | ------------------------------- | ---------------------------- | ------------ | --------------- |
| 1           | Query Optimisation + Conn. Pool | Basic optimisations, Caching | 🔼 Moderate  | 💰 Low          |
| 2           | Vertical Scaling                | Bigger machine               | 🔼 Limited   | 💸 High (later) |
| 3           | CQRS                            | Read-Write Separation        | 🔼 High      | 💰 Medium       |
| 4           | Multi Primary Replication       | Multi-node writes            | 🔼 Higher    | 💸 High         |
| 5           | Partitioning by Functionality   | DB based on domain           | 🔼 Very High | 💸 Variable     |
| 6           | Horizontal Scaling              | Sharding                     | 🔼 Global    | 💸 Complex      |
| 7           | Data Centre Partition           | Cross-DC availability        | 🌍 Maximal   | 💸💸 High       |

---

Let me know if you'd like this exported as a **PDF**, or embedded in **Notion/Obsidian-style** format for revision!
