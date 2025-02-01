#include <iostream>
#include <winsock2.h>
#include <iphlpapi.h>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

// Function to scan ports
bool scanPort(const std::string &ip, int port)
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());

    int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    closesocket(sock);

    return result == 0;
}

// Function for the Ping test
bool ping(const std::string &ip)
{
    std::string command = "ping -n 1 " + ip;
    int result = system(command.c_str());
    return result == 0;
}

// Function to display the menu
void displayMenu()
{
    std::cout << "\nPlease select an option:\n";
    std::cout << "1. Scan network\n";
    std::cout << "2. Test ping status of IPs\n";
    std::cout << "3. Perform port scan\n";
    std::cout << "4. Trace route\n";
    std::cout << "5. DNS lookup\n";
    std::cout << "6. List network interfaces\n";
    std::cout << "7. Get public IP\n";
    std::cout << "8. Check open Wi-Fi networks\n";
    std::cout << "9. Get MAC address of device\n";
    std::cout << "10. Network speed test\n";
    std::cout << "11. Perform reverse DNS lookup\n";
    std::cout << "12. Get local network statistics\n";
    std::cout << "13. Check IP availability\n";
    std::cout << "14. List active connections\n";
    std::cout << "15. Show routing table\n";
    std::cout << "16. Check DNS server status\n";
    std::cout << "17. Show ARP cache\n";
    std::cout << "18. Check HTTP response header\n";
    std::cout << "19. Perform Whois lookup\n";
    std::cout << "20. Check open ports on a device\n";
    std::cout << "21. Show SSL certificate details\n";
    std::cout << "22. Show all active sessions\n";
    std::cout << "23. Get DNS records\n";
    std::cout << "24. Show firewall status\n";
    std::cout << "25. Check HTTP status code\n";
    std::cout << "26. List network shares\n";
    std::cout << "27. Get operating system information\n";
    std::cout << "28. List devices in network\n";
    std::cout << "29. Show available network adapters\n";
    std::cout << "30. Trace route to multiple destinations\n";
    std::cout << "31. Exit\n";
}

// Function to scan the network
void networkScan(const std::string &ipBase)
{
    std::vector<int> ports = {80, 443, 21, 22, 25, 53}; // Common ports
    for (int i = 1; i <= 255; ++i)
    {
        std::string ip = ipBase + "." + std::to_string(i);
        if (ping(ip))
        {
            std::cout << "Device found: " << ip << std::endl;
        }
    }
}

// Function for port scanning
void portScan(const std::string &ipBase)
{
    std::vector<int> ports = {80, 443, 21, 22, 25, 53}; // Common ports
    for (int i = 1; i <= 255; ++i)
    {
        std::string ip = ipBase + "." + std::to_string(i);
        if (ping(ip))
        {
            std::cout << "Device found: " << ip << std::endl;
            for (int port : ports)
            {
                if (scanPort(ip, port))
                {
                    std::cout << "Open port " << port << " on " << ip << std::endl;
                }
            }
        }
    }
}

// Function for trace route
void traceRoute(const std::string &ip)
{
    std::string command = "tracert " + ip;
    system(command.c_str());
}

// Function to perform DNS lookup
void dnsLookup(const std::string &domain)
{
    std::string command = "nslookup " + domain;
    system(command.c_str());
}

// Function to list network interfaces
void listNetworkInterfaces()
{
    system("ipconfig /all");
}

// Function to get public IP
void getPublicIP()
{
    system("curl ifconfig.me");
}

// Function to scan Wi-Fi networks
void scanWiFi()
{
    system("netsh wlan show networks");
}

// Function to get the MAC address of a device
void getMACAddress()
{
    system("getmac");
}

// Function to perform a simple speed test
void networkSpeedTest()
{
    system("speedtest-cli");
}

// Function for reverse DNS lookup
void reverseDNS(const std::string &ip)
{
    std::string command = "nslookup " + ip;
    system(command.c_str());
}

// Function to get local network statistics
void getNetworkStats()
{
    system("netstat -s");
}

// Function to check IP availability
bool checkIPAvailability(const std::string &ip)
{
    return ping(ip);
}

// Function to list active connections
void listActiveConnections()
{
    system("netstat -an");
}

// Function to show the routing table
void showRoutingTable()
{
    system("route print");
}

// Function to check DNS server status
void checkDNSStatus()
{
    system("nslookup");
}

// Function to show ARP cache
void showARP()
{
    system("arp -a");
}

// Function to check HTTP response header
void checkHTTPHeader(const std::string &url)
{
    std::string command = "curl -I " + url;
    system(command.c_str());
}

// Function to perform Whois lookup
void whoisLookup(const std::string &domain)
{
    std::string command = "whois " + domain;
    system(command.c_str());
}

// Function to check open ports on a device
void checkOpenPorts(const std::string &ip)
{
    portScan(ip);
}

// Function to show SSL certificate details
void showSSLCertificate(const std::string &url)
{
    std::string command = "echo | openssl s_client -connect " + url + ":443 | openssl x509 -text";
    system(command.c_str());
}

// Function to show all active sessions
void showActiveSessions()
{
    system("query user");
}

// Function to get DNS records
void getDNSRecords(const std::string &domain)
{
    std::string command = "nslookup -type=any " + domain;
    system(command.c_str());
}

// Function to show firewall status
void showFirewallStatus()
{
    system("netsh advfirewall show allprofiles");
}

// Function to check HTTP status code
void checkHTTPStatusCode(const std::string &url)
{
    std::string command = "curl -o /dev/null -s -w \"%{http_code}\" " + url;
    system(command.c_str());
}

// Function to list network shares
void listNetworkShares()
{
    system("net view");
}

// Function to get operating system information
void getOSInfo()
{
    system("systeminfo");
}

// Function to list devices in network
void listNetworkDevices()
{
    system("net view");
}

// Function to show available network adapters
void showNetworkAdapters()
{
    system("wmic nic get name, index");
}

// Function to trace route to multiple destinations
void traceRouteMultiple(const std::vector<std::string> &ips)
{
    for (const std::string &ip : ips)
    {
        traceRoute(ip);
    }
}

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    std::string ipBase = "192.168.1"; // Example subnet

    int option;
    do
    {
        displayMenu();
        std::cout << "Select an option: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            std::cout << "Scanning the network...\n";
            networkScan(ipBase);
            break;
        case 2:
            std::cout << "Performing ping test...\n";
            networkScan(ipBase); // Only find devices
            break;
        case 3:
            std::cout << "Performing port scan...\n";
            portScan(ipBase); // Only scan ports
            break;
        case 4:
        {
            std::string ip;
            std::cout << "Enter IP for trace route: ";
            std::cin >> ip;
            std::cout << "Tracing route...\n";
            traceRoute(ip);
        }
        break;
        case 5:
        {
            std::string domain;
            std::cout << "Enter domain for DNS lookup: ";
            std::cin >> domain;
            dnsLookup(domain);
        }
        break;
        case 6:
            std::cout << "Listing network interfaces...\n";
            listNetworkInterfaces();
            break;
        case 7:
            std::cout << "Getting public IP...\n";
            getPublicIP();
            break;
        case 8:
            std::cout << "Scanning Wi-Fi networks...\n";
            scanWiFi();
            break;
        case 9:
            std::cout << "Getting MAC address...\n";
            getMACAddress();
            break;
        case 10:
            std::cout << "Performing network speed test...\n";
            networkSpeedTest();
            break;
        case 11:
        {
            std::string ip;
            std::cout << "Enter IP for reverse DNS lookup: ";
            std::cin >> ip;
            reverseDNS(ip);
        }
        break;
        case 12:
            std::cout << "Getting network statistics...\n";
            getNetworkStats();
            break;
        case 13:
        {
            std::string ip;
            std::cout << "Enter IP to check availability: ";
            std::cin >> ip;
            if (checkIPAvailability(ip))
            {
                std::cout << ip << " is available.\n";
            }
            else
            {
                std::cout << ip << " is not available.\n";
            }
        }
        break;
        case 14:
            std::cout << "Listing active connections...\n";
            listActiveConnections();
            break;
        case 15:
            std::cout << "Showing routing table...\n";
            showRoutingTable();
            break;
        case 16:
            std::cout << "Checking DNS server status...\n";
            checkDNSStatus();
            break;
        case 17:
            std::cout << "Showing ARP cache...\n";
            showARP();
            break;
        case 18:
        {
            std::string url;
            std::cout << "Enter URL for HTTP header check: ";
            std::cin >> url;
            checkHTTPHeader(url);
        }
        break;
        case 19:
        {
            std::string domain;
            std::cout << "Enter domain for Whois lookup: ";
            std::cin >> domain;
            whoisLookup(domain);
        }
        break;
        case 20:
        {
            std::string ip;
            std::cout << "Enter IP to check open ports: ";
            std::cin >> ip;
            checkOpenPorts(ip);
        }
        break;
        case 21:
        {
            std::string url;
            std::cout << "Enter URL to show SSL certificate details: ";
            std::cin >> url;
            showSSLCertificate(url);
        }
        break;
        case 22:
            std::cout << "Showing active sessions...\n";
            showActiveSessions();
            break;
        case 23:
        {
            std::string domain;
            std::cout << "Enter domain for DNS records: ";
            std::cin >> domain;
            getDNSRecords(domain);
        }
        break;
        case 24:
            std::cout << "Showing firewall status...\n";
            showFirewallStatus();
            break;
        case 25:
        {
            std::string url;
            std::cout << "Enter URL for HTTP status check: ";
            std::cin >> url;
            checkHTTPStatusCode(url);
        }
        break;
        case 26:
            std::cout << "Listing network shares...\n";
            listNetworkShares();
            break;
        case 27:
            std::cout << "Getting OS information...\n";
            getOSInfo();
            break;
        case 28:
            std::cout << "Listing devices in network...\n";
            listNetworkDevices();
            break;
        case 29:
            std::cout << "Showing available network adapters...\n";
            showNetworkAdapters();
            break;
        case 30:
        {
            std::vector<std::string> ips;
            std::cout << "Enter IPs to trace (comma separated): ";
            std::cin.ignore();
            std::string ips_input;
            std::getline(std::cin, ips_input);
            std::stringstream ss(ips_input);
            std::string ip;
            while (std::getline(ss, ip, ','))
            {
                ips.push_back(ip);
            }
            traceRouteMultiple(ips);
        }
        break;
        case 31:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    } while (option != 31);

    WSACleanup();
    return 0;
}
