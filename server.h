#define Server_H
#include <inttypes.h>
#include <netinet/in.h>
#include <sys/socket.h>

struct Header {
  uint16_t flags;
  uint16_t checksum;
  uint32_t size;
};

// Impement needed flags

typedef struct Header Header;

struct Packet {
  Header header;
  char data[1024 - sizeof(header)];
};

struct Client {
  int32_t socket;
  struct sockaddr_in addr;
  int next_seqno; // if needed
};

typedef struct Client Client;
typedef struct Packet Packet;

// Creates an empty Client
Client create_client();

// Returns 0 in case of failure and 1 in case of success
int setup_client(Client client, const char *servername, uint16_t server_port);

int send_data(Client client, char *buffer, size_t size);

int recv_data(Client client, char *buffer, size_t size);
