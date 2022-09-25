#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

void send_filename(int sock)
{
	char buffer[1024] = {0};
	printf("Write filename: ");
	scanf("%s", buffer);
	sprintf(buffer, "%s", buffer);
	send(sock, buffer, sizeof(buffer), 0);
}

void request_filecontent(int sock)
{
	char buffer[1024] = {0};
	printf("File content: \n");
	read(sock, buffer, sizeof(buffer) - 1);
	printf("%s\n", buffer);
}

int main(int argc, char const* argv[])
{
	int sock = 0, valread, client_fd;
	struct sockaddr_in serv_addr;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
		<= 0) {
		printf(
			"\nInvalid address/ Address not supported \n");
		return -1;
	}

	if ((client_fd = connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr))) < 0) {
		printf("\nConnection Failed \n");
		return -1;
	}
	
	while(1) {
		send_filename(sock);
		request_filecontent(sock);
	}

	close(client_fd);
	return 0;
}


