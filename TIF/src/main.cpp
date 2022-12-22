#include "../headers/hotel.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  Hotel hotel;
  initHotel(hotel);

  while (true) {
    int selection = mainMenu();
    switch (selection) {
      case 1: {
        Guest guest = getGuestInfo();
        addGuest(hotel, guest);
        break;
      }
      case 2: {
        int room;
        cout << "Ingrese el número de habitación del huésped a registrar como salido: ";
        cin >> room;
        checkOut(hotel, room);
        break;
      }
      case 3:
        listGuests(hotel);
        break;
      case 4:
        return 0;
      default:
        cout << "Opción inválida, por favor seleccione una opción válida del menú." << endl;
        break;
    }
  }
}