#include <arpa/inet.h>
#include <errno.h>
#include <net/if.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int get_netif_mac(const char *_ifr_name, uint8_t *_mac) {
    int32_t ret = -1;
    struct ifreq m_ifreq;
    int32_t sock = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("socket err\r\n");
        goto err;
    }

    strcpy(m_ifreq.ifr_name, _ifr_name);

    ret = ioctl(sock, SIOCGIFHWADDR, &m_ifreq);
    if (ret < 0) {
        printf("ioctl err:%d\r\n", ret);
        goto err;
    }

    snprintf((char *)_mac, 32, "%02x%02x%02x%02x%02x%02x", (uint8_t)m_ifreq.ifr_hwaddr.sa_data[0],
             (uint8_t)m_ifreq.ifr_hwaddr.sa_data[1],
             (uint8_t)m_ifreq.ifr_hwaddr.sa_data[2],
             (uint8_t)m_ifreq.ifr_hwaddr.sa_data[3],
             (uint8_t)m_ifreq.ifr_hwaddr.sa_data[4],
             (uint8_t)m_ifreq.ifr_hwaddr.sa_data[5]);

    return 0;
err:
    perror("error");
    return -1;
}

int main() {
    char mac_str[32] = {0};
    get_netif_mac("wlp3s0", (unsigned char *)mac_str);
    printf("mac = %s\n", mac_str);

    return 0;
}