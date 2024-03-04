// Server
#include <SFML/Network.hpp>
#include <iostream>
#include <SFML/Network/Packet.hpp>

int main() {
    sf::TcpListener listener;
    sf::TcpSocket client;
    sf::Packet packet;
    std::string message;

    if (listener.listen(53000, sf::IpAddress::Any) != sf::Socket::Done) {
        std::cout << "Not connected" << std::endl;
    }

    std::cout << "Server is listening..." << std::endl;

    if (listener.accept(client) != sf::Socket::Done) {
        std::cout << "Client yet not connected " << std::endl;
    }

    while (true) {
        if (client.receive(packet) == sf::Socket::Done) {
            packet >> message;
            std::cout << "Client: " << message << std::endl;
        }

        std::cout << "Server: ";
        std::getline(std::cin, message);
        packet.clear();
        packet << message;
        client.send(packet);
    }

    return 0;
}
