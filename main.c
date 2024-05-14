#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOMAINS 10

void print_ip_address(char *domain) {
    struct hostent *host_info = gethostbyname(domain);

    if (host_info == NULL) {
        printf("Failed to resolve domain: %s\n", domain);
        return;
    }
    printf("IP Address: %s\n", domain, inet_ntoa(*(struct in_addr *)host_info->h_addr_list[0]));
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: %s <domain1> [<domain2>...]\n", argv[0]);
        return 1;
    }
    int num_domains = argc - 1;
    if (num_domains > MAX_DOMAINS) {
        printf("Too many domains. (Maximum: %d)", MAX_DOMAINS);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        print_ip_address(argv[i]);
    }
}