# VMs and Deploying a MERN app
# Why deploy on the internet, isn’t [localhost](http://localhost:3000/) enough?

## Whats wrong in the following message? Is jimmy lying?
```
Messages            Jimmy                       Details
----------------------------------------------------------
Jimmy:   Hey bro, after days of 
         hard work, I finally built 
         a website

You:     That's awesome!

Jimmy:   Can you check it out??

Jimmy:   http://localhost:3000/hi

You:     Looks great bro!

Jimmy:   Thanks bro!
----------------------------------------------------------

```

# Domains vs IPs

## localhost

```
        +------------------------+                +------------------------+
        |      Bali's Mac        |                |       Raman's Mac      |
        |                        |                |                        |
        |  http://localhost:3000 |                |  http://localhost:3000 |
        |     (runs server)      |                |   (no server here 😭)   |
        |         ↑              |                |         ↑              |
        |         |              |                |         |              |
        |   Points to THIS MAC   |                |   Points to THIS MAC   |
        +------------------------+                +------------------------+

      ⚠ Localhost always loops back to the computer it's typed on.
      ❌ Raman can't access Bali's server using localhost.

```
"Localhost" refers to the computer you're currently working on. It's essentially a loopback address that points to the machine itself, allowing it to communicate with itself over a network. In technical terms, the IP address for localhost is usually `127.0.0.1` for IPv4, or `::1` for IPv6.

## ping command

- Try running

```solidity
ping localhost
```

- Now try pinging google

```solidity
ping google.com
```

Notice google points to a different `IP address` .

### **IP (Internet Protocol) Address:**

- An **IP address** is a unique string of numbers that identifies a device on a network, like the internet. Think of it like a **house address**: it's how computers (or any devices on the network) know where to send information.
- For example, `192.168.1.1` is an IP address.
- An **IP address** is essential for routing data on the internet, but it's not the most human-friendly system.

### Domain name

- A **domain name** is the readable, human-friendly address we use to access websites, like `google.com` or `example.org`.
- Domains are a higher-level abstraction that makes it easier for us to remember websites instead of trying to recall a string of numbers (like an IP address).
- For instance, when you type `www.google.com` into your browser, your computer looks up that domain name and finds the corresponding IP address, then connects to the website.

## Domain name vs Phone number
```
+------------------------------+
|         Contacts             |
+------------------------------+
|   Name:      Doctor          |   --> Domain Name (e.g., www.google.com)
|                              |
|   Work:      0931 𐰴          |   --> IP Address / Phone Number
|                              |
|   Message   Call   Video     |
|   Mail                      |
+------------------------------+

```
## Limited IP addresses

There are limited number of IP addresses in the world (ipv4 specially). So it’s not very easy for us to get a public IP. Most IPs are blocked by cloud providers or Big companies (JIO)


# Local network, routing (mild hosting)

If you have multiple laptops on the same `wifi router`, you can access one machine from another by using their private IP address. This is a `mild` version of deploying your app on your `local network` (or whats called the intranet)
```
                             🌐 ROUTER
                         +----------------+
                         |   Home Router  |
                         +--------+-------+
                                  |
       -------------------------------------------------
       |                                               | 
+---------------------+                       +----------------------+
|   Bali's Mac        |                       |    Raman's Mac       |
|                     |                       |                      |
|  Tries to open:     |  ===(via router)===>  |  Runs server at:     |
|  http://192.168.0.5:3000                    |  http://localhost:3000|
|                     |                       |  (localhost = self)   |
+---------------------+                       +----------------------+

✅ Same Wi-Fi or LAN (behind same router)
✅ IP must be Raman’s local IP (not 127.0.0.1)
❌ `localhost` ≠ shared

```

## Steps to follow

1. Start a node.js process locally on port 3000

```solidity
const express = require('express');
const app = express();
const port = 3000;

app.get('/', (req, res) => {
  res.send('Hello, World!');
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
```

1. Find the IP of your machine on the local network

```solidity
ifconfig or ipconfig
```

**Loopback address**
```bash
lo0: flags=8049<UP,LOOPBACK,RUNNING,MULTICAST> mtu 16384
	options=1203<RXCSUM,TXCSUM,TXSTATUS,SW_TIMESTAMP>
	inet 127.0.0.1 netmask 0xff000000
	inet6 ::1 prefixlen 128
	inet6 fe80::1%lo0 prefixlen 64 scopeid 0x1
	nd6 options=201<PERFORMNUD,DAD>

```
```
+---------------------------+
| Interface: lo0           |
| Flags: LOOPBACK, UP      |
| IP: 127.0.0.1            |  --> IPv4 loopback (localhost)
| IPv6: ::1                |  --> IPv6 loopback
+---------------------------+

🧠 127.0.0.1 = 'localhost'
📍 Resides on *your* computer only
🔄 Used for testing/dev servers locally
🚫 Not accessible from other machines

```
Ethernet 0 network
```status: inactive
en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	options=6463<RXCSUM,TXCSUM,TSO4,TSO6,CHANNEL_IO,PARTIAL_CSUM,ZEROINVERT_CSUM>
	ether f4:d4:88:3e:95:e4
	inet6 fe80::1078:fa14:2c87:51cc%en0 prefixlen 64 secured scopeid 0xe
	inet 192.168.1.3 netmask 0xffffff00 broadcast 192.168.1.255
	inet6 2401:4900:1cd7:e0e0:10e7:64eb:9977:d498 prefixlen 64 autoconf secured
	inet6 2401:4900:1cd7:e0e0:99cf:bda9:a8bc:90be prefixlen 64 autoconf temporary
	nd6 options=201<PERFORMNUD,DAD>
media: autoselect
status: active
```
```
en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
    options=...                          # Various network options enabled
    ether f4:d4:88:5e:95:e4              # MAC address (hardware address)
    inet 192.168.1.3 netmask 0xffffff00  # IPv4 address and netmask
    broadcast 192.168.1.255              # Broadcast address for the subnet
    inet6 fe80::1078:fa14:2c87:51cc%en0  # IPv6 link-local address
    inet6 2401:...                       # Public IPv6 address
    ...
    status: active                       # Interface is active and running

```
| Field             | ASCII/Meaning                                                                |
| ----------------- | ---------------------------------------------------------------------------- |
| `en0`             | Interface name (usually Ethernet or Wi-Fi on macOS)                          |
| `flags=8863<...>` | Bitwise flags showing the interface is UP, capable of BROADCAST, etc.        |
| `mtu 1500`        | Maximum Transmission Unit size in bytes                                      |
| `ether`           | MAC (Media Access Control) address (unique identifier for network interface) |
| `inet`            | IPv4 address (here it's `192.168.1.3`)                                       |
| `netmask`         | Subnet mask (in hex), `0xffffff00` = 255.255.255.0                           |
| `broadcast`       | IPv4 broadcast address                                                       |
| `inet6`           | IPv6 addresses (can be link-local, global, temporary)                        |
| `status: active`  | The interface is connected and functioning                                   |

If I go to 192.168.1.3:3000 on my phone, I should be able to visit the website
```
+------------------------------+
|  192.168.1.3:3000            |  <- Browser address bar
+------------------------------+
|  Hello, World!               |  <- Page content
|                              |
+------------------------------+
```
Hosts file
You can override what your domain name resolves to by overriding the hosts file.
```bash
vi /etc/hosts
127.0.0.01	harkirat.100xdevs.com
```
```
+-----------------------------------------------------+
| ◁  ▷ ⟳🔖  ⚠ Not Secure  harkirat.100xdevs.com:3000 |
+-----------------------------------------------------+
|                                                     |
|  Hello, World!                                      |
|                                                     |
+-----------------------------------------------------+

```
Can you think of how you can phis your friend into giving their credentials by using this approach?


# How to deploy apps (actual hosting)?

1. Renting servers on a cloud
2. Rending compute yourself in datacenters
3. Self hosting (buying a CPU rack in your house)
4. Serverless providers
5. Cloud native options (k8s)

### Great video to look at -
https://www.youtube.com/watch?v=gViEtIJ1DCw

# What is a VM
```
                             🌍 World Map - Dummy Server Locations 🌍

   +--------------------------------------------------------------------------------+
   |                                                                                |
   |           🇨🇦 CANADA [🖥]               🇷🇺 RUSSIA [🖥][🖥]                   |
   |               🇺🇸 USA [🖥]                  🇰🇿 KAZAKHSTAN [🖥]                |
   |                                                                                |
   |                                                                                |
   |      🌊              🌊             🇨🇳 CHINA [🖥][🖥]             🌊         |
   |   🌊      NORTH AMERICA     🌊         🌊     ASIA       🌊                  |
   |                                                                                |
   |                                                                                |
   |            🌊                 🌍 EUROPE 🌍               🌊                 |
   |        🌊                         🌊                        🌊               |
   |                                                                                |
   |                      🌍 AFRICA 🌍                          🌊                |
   |                          🇲🇱 MALI [🖥]                                        |
   |                                                                                |
   |   🌊         🌊                                     🌊                     |
   |            🌊        SOUTH AMERICA         🌊      OCEANIA/AUSTRALIA         |
   |                     🌎 BRAZIL, ARGENTINA 🌎         🇦🇺 AUSTRALIA            |
   +--------------------------------------------------------------------------------+

Legend:
[🖥] = Server Location
🌊 = Ocean     🌍 = Continent Marker

```
```
        🌍 World Map - Server Locations

             +-------------------------+
             |                         |
             |   🇨🇦 Canada     [🖥]     |
             |   🇺🇸 USA        [🖥]     |
             |                         |
             |   🇲🇱 Mali       [🖥]     |
             |                         |
             |   🇷🇺 Russia     [🖥]     |
             |   🇰🇿 Kazakhstan [🖥]     |
             |   🇨🇳 China      [🖥]     |
             |                         |
             +-------------------------+

Legend:
[🖥] = Server Location

```
VMs run on a physical server (called the **host**) but are abstracted through a layer of virtualization software called a **hypervisor** (e.g., VMware, KVM). This hypervisor divides the host machine’s resources (CPU, memory, storage) into separate virtual machines.
```
     +---------+   +---------+   +---------+
     |  VM1    |   |  VM2    |   |  VM3    |
     |  OS     |   |  OS     |   |  OS     |
     +---------+   +---------+   +---------+
           \         |         /
            \        |        /
          +-----------------------+
          |      Hypervisor       |
          +-----------------------+
                  |
                  v
          +-----------------------+
          |       Hardware        |
          +-----------------------+

```
Each VM acts like a completely independent machine, even though they share the underlying hardware. You can run different operating systems and applications in different VMs on the same physical server.

VMs are highly flexible and easy to scale. You can quickly spin up, modify, or delete VMs, and you can consolidate multiple workloads on a single server.

The virtualization layer introduces a slight overhead in terms of performance because the hypervisor needs to manage resources and ensure each VM operates independently. However, with modern hypervisors and powerful hardware, this overhead is minimal.
# Bare metal servers

n a bare-metal setup, an operating system (OS) runs directly on the physical hardware without a hypervisor in between. There’s no virtualization layer.
```
       +-------------------+
       |       OS          |
       +-------------------+
               |
               v
       +-------------------+
       |     Hardware       |
       +-------------------+

```
 Since there's no hypervisor, bare-metal systems tend to offer better performance, as the OS can directly access all the server’s resources without sharing them with other instances. This is especially important for high-performance applications like large databases, gaming servers, or mining crypto

With bare-metal, you’re typically limited to the resources (CPU, memory, storage) of the actual physical server. You can't dynamically allocate resources like you can in a VM.

# SSH protocol, password based auth

The **SSH protocol** (Secure Shell) is a cryptographic network protocol that allows secure communication between two systems, typically for remote administration. It’s most commonly used to log into remote servers and execute commands, but it also facilitates secure file transfers and other operations.

### Key Features of SSH:

1. **Encryption**: SSH encrypts the data that’s sent between the client and the server, so even if someone intercepts the connection, they can’t read the data. This makes it much more secure than older protocols like Telnet or FTP, which transmit data in plaintext.
2. **Authentication**: SSH can use two methods of authentication:
    - **Password-based**: You enter a password to authenticate yourself to the remote system.
    - **Public Key-based**: A more secure method, where the client uses a private key to authenticate, and the server checks it against the corresponding public key. This eliminates the need for passwords and provides an extra layer of security.
3. **Integrity**: SSH ensures the integrity of data, meaning that data cannot be tampered with while it’s in transit. If someone tries to alter the data being sent, the connection will be immediately disrupted.

## Password based

While setting up a server, select password based authentication

**Example from `digitalocean`**

```
+--------------------------------------------------------------+
|                       Create Droplets                        |
|    Droplets are virtual machines that anyone can set up...  |
+--------------------------------------------------------------+

Choose Region:
+-----------+  +----------------+  +-------------+
|  New York |  | San Francisco |  |  Amsterdam  |
+-----------+  +----------------+  +-------------+
+-----------+  +--------+  +---------+  +--------+
| Singapore |  | London |  | Frankfurt | | Sydney |
+-----------+  +--------+  +-----------+ +--------+
+---------+  +-----------+
| Toronto |  | Bangalore |
+---------+  +-----------+

Datacenter:
+------------------------------+
| New York • Datacenter 1 NYC1|
+------------------------------+

🔔 Tip:
Avoid latency by selecting a region closest to you or your users.

VPC Network:
+-----------------------------+
| default-nyc1 [DEFAULT]      |
| All droplets in same VPC.  |
+-----------------------------+

💵 Pricing Summary:
+-------------------------+
| $32.00/month            |
| $0.048/hour             |
+-------------------------+

Action:
[ CREATE VIA COMMAND LINE ]   [Create Droplet (disabled)]

```
```
+---------------------------------------------------+
|         Choose Authentication Method              |
|                                                   |
|   ( ) SSH Key                                     |
|       Connect to your Droplet with an SSH key     |
|                                                   |
|   (*) Password                                     |
|       Connect to your Droplet as "root" via pwd   |
|                                                   |
|   +-------------------------------------------+   |
|   |  Create root password: [•••••••••••••••]   |   |
|   +-------------------------------------------+   |
|                                                   |
|   Password Requirements:                          |
|   - At least 8 characters                         |
|   - 1 uppercase letter (not first/last)           |
|   - 1 number                                      |
|   - Cannot end in number/special character        |
|                                                   |
|   ⚠ Store your password securely.                 |
|     You will NOT receive an email with it.        |
+---------------------------------------------------+

```

```bash
ssh ubuntu@SERVER_IP
or
ssh root@SERVER_IP
```
# SSH protocol, ssh keypair based

Generate a new public private keypair

```solidity
ssh-keygen
```

Explore your public and private key

```solidity
cat ~/.ssh/id_rsa.pub
cat ~/.ssh/id_rsa
```

- Try adding it to Github so you can push to github without password
```
+-----------------------------------------------------+
|                  GitHub Settings                    |
|-----------------------------------------------------|
| Profile: Kirat (hkirat)                             |
|   [Switch settings context]                         |
|                                                     |
| [🔓] Public profile                                 |
| [⚙️ ] Account                                        |
| [🎨] Appearance                                     |
| [♿] Accessibility                                  |
| [🔔] Notifications                                  |
|                                                     |
| Access:                                             |
|   [💳] Billing and plans                            |
|   [📧] Emails                                       |
|   [🔐] Password and authentication                  |
|   [📡] Sessions                                     |
|   [🔑] SSH and GPG keys [Selected]                  |
|   [🏢] Organizations                                |
+-----------------------------------------------------+

> SSH keys
This is a list of SSH keys associated with your account.

Authentication keys:
+---------------------------------------------+
|  🔑 didi mac                                 |
|  SHA256:VDWz2a2...                          |
|  Added on Mar 27                            |
|  Last used within the last week             |
+---------------------------------------------+

[Link] → Guide to connecting via SSH

> GPG keys
(This section is shown below but not visible in this screenshot)

```
- Try adding it to digitalocean and ssh using it.
```
+------------------------------------------------------------+
|              Choose Authentication Method                 |
+------------------------------------------------------------+

 (•) SSH Key                         ( ) Password
      Connect to your               Connect to your Droplet
      Droplet with an               as the "root" user via
      SSH key pair                  password

+------------------------------------------------------------+
| Choose your SSH keys:                                     |
|   [✔] kirat-local                                          |
|                                                            |
|   [ New SSH Key ]                                          |
+------------------------------------------------------------+
```

```bash
ssh ubuntu@IP
or
git clone git@github.com:100xdevs-cohort-3/week-24-deposit-with-infra.git (try a private repo)
```
## ✅ ASCII Diagram – SSH Session to Ubuntu Server
```
+--------------------------------------------------------------+
| test-app-123 ssh root@146.190.221.189                        |
|                                                              |
| Enter passphrase for key '/Users/harkiratsingh/.ssh/id_rsa' |
| ... (prompt repeated 3 times)                                |
|                                                              |
| Welcome to Ubuntu 24.10 (GNU/Linux 6.11.0-9-generic x86_64) |
|                                                              |
| * Documentation: https://help.ubuntu.com                    |
| * Management:     https://landscape.canonical.com            |
| * Support:        https://ubuntu.com/pro                     |
|                                                              |
| System Information (as of Sat Jan 25 14:06:06 UTC 2025):     |
|  - System load: 0.0                                          |
|  - Usage of /: 1.6% of 115.25GB                              |
|  - Memory usage: 5%                                          |
|  - Swap usage: 0%                                            |
|  - Processes: 116                                            |
|  - Users logged in: 0                                        |
|  - IPv4 (eth0): 146.190.221.189                              |
|  - IPv4 (eth0): 10.10.0.5                                    |
|                                                              |
| 95 updates available (35 are security updates)               |
| To upgrade: apt list --upgradable                            |
|                                                              |
| Last login: Sat Jan 25 14:00:39 2025 from 106.219.121.16     |
|                                                              |
| root@backend-1:~# █                                          |
+--------------------------------------------------------------+

```
Check `authorized_keys`

```solidity
cat ~/.ssh/authorized_keys
```

### How to hack your friends laptop?

Put your public key in your friends laptop as an authorized key.

## Algorithms for public key cryptography

The `ssh-keygen` tool can generate SSH key pairs using several different cryptographic algorithms, depending on what you choose during the key creation process. By default, it typically uses **RSA**, but you can specify other algorithms as well. Here are the most commonly used algorithms:

### **1. RSA (Rivest–Shamir–Adleman)**

- **Default Algorithm** (for most systems): The `ssh-keygen` tool uses RSA by default when creating keys.
- RSA is a widely-used public-key algorithm that provides strong security.

### **2. Ed25519**

- **A newer and more secure option**: Ed25519 is a modern elliptic curve algorithm that is designed to provide both high security and efficiency.
- It’s **faster**, more **secure** for the same key size, and less prone to certain vulnerabilities compared to RSA.

```solidity
ssh-keygen -t ed25519
```

### **3. ECDSA (Elliptic Curve Digital Signature Algorithm)**

- **Another elliptic curve algorithm**, which is considered a more secure and efficient alternative to RSA for most use cases.
# IP address of your machine

If you get a VM on digitalocean, there is an associated IP address to it. This is a public IP address that you can use to reach the server anywhere around the world
```
+--------------------------------------------------------------+
|                   🔍 Search by Droplet name                  |
+--------------------------------------------------------------+

+-----------------------------------------------------------------------+
| Name        | IP Address      | Created        | Tags | Actions       |
|-------------|------------------|----------------|------|----------------|
| 🟢 backend-1 | 146.190.221.189  | 3 minutes ago  |      | [Upsize] [More▼]|
|             | 4 GB / 2 vCPUs / 120 GB Disk / NYC1                   |
+-----------------------------------------------------------------------+

```
