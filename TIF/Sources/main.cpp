#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <limits>

using namespace std;

// Estructura para almacenar la información de un huésped
struct Guest {
  string name;
  string address;
  string phone;
  int room;
};

// Estructura para almacenar la información de un hotel
struct Hotel {
  list<Guest> guests;
};

// Inicializa un hotel
void initHotel(Hotel& hotel) {
  // Limpia la lista de huéspedes
  hotel.guests.clear();
}

// Agrega un huésped al hotel
void addGuest(Hotel& hotel, const Guest& guest) {
  // Agrega el huésped a la lista de huéspedes
  hotel.guests.push_back(guest);
}

// Elimina a un huésped del hotel
void checkOut(Hotel& hotel, int room) {
  // Recorre la lista de huéspedes buscando el huésped con el número de habitación especificado
  for (auto it = hotel.guests.begin(); it != hotel.guests.end(); it++) {
    if (it->room == room) {
      // Elimina el huésped de la lista
      hotel.guests.erase(it);
      cout << "El huésped de la habitación " << room << " ha sido registrado como salido." << endl;
      return;
    }
  }

  throw runtime_error("No se ha encontrado ningún huésped en la habitación " + to_string(room) + ".");
}

// Muestra una lista de huéspedes actuales en el hotel
void listGuests(const Hotel& hotel) {
  cout << "Lista de huéspedes:" << endl;
  // Recorre la lista de huéspedes y muestra el nombre y número de habitación de cada huésped
  for (const Guest& guest : hotel.guests) {
    cout << guest.name << ", habitación " << guest.room << endl;
  }
}

// Muestra el menú principal y permite al usuario seleccionar una opción
int mainMenu() {
  cout << "Seleccione una opción:" << endl;
  cout << "1. Ingresar nuevo huésped" << endl;
  cout << "2. Registro de salida de huésped" << endl;
  cout << "3. Ver lista de huéspedes" << endl;
  cout << "4. Salir" << endl;
  int selection;
  cin >> selection;
  if (cin.fail()) {
    // Limpia y resetea el flujo de entrada
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Vuelve a pedir la selección al usuario
    cout << "Por favor, seleccione una opción válida: ";
    cin >> selection;
  }
  return selection;
}

// Pide al usuario que ingrese la información de un huésped y la devuelve en una estructura Guest
Guest getGuestInfo() {
  string name, address, phone;
  int room;
  cout << "Ingrese el nombre del huésped: ";
  cin.ignore();
  getline(cin, name);
  cout << "Ingrese la dirección del huésped: ";
  getline(cin, address);
  cout << "Ingrese el número de teléfono del huésped: ";
  getline(cin, phone);
  cout << "Ingrese el número de habitación del huésped: ";
  cin >> room;
  if (cin.fail()) {
    // Limpia y resetea el flujo de entrada
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Vuelve a pedir el número de habitación al usuario
    cout << "Por favor, ingrese un número de habitación válido: ";
    cin >> room;
  }
  return { name, address, phone, room };
}

// Pide al usuario que ingrese el número de habitación de un huésped y lo devuelve
int getRoomNumber() {
  int room;
  cout << "Ingrese el número de habitación del huésped: ";
  cin >> room;
  if (cin.fail()) {
    // Limpia y resetea el flujo de entrada
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Vuelve a pedir el número de habitación al usuario
    cout << "Por favor, ingrese un número de habitación válido: ";
    cin >> room;
  }
  return room;
}

int main() {
  Hotel hotel;
  initHotel(hotel);

  // Bucle principal del programa
  while (true) {
    // Muestra el menú principal y obtiene la opción seleccionada por el usuario
    int selection = mainMenu();

    try {
      // Ejecuta la acción correspondiente a la opción seleccionada
      switch (selection) {
      case 1: {
          // Pide al usuario que ingrese la información del nuevo huésped
          Guest guest = getGuestInfo();
          // Agrega el huésped al hotel
          addGuest(hotel, guest);
          break;
        }
      case 2: {
          // Pide al usuario que ingrese el número de habitación del huésped que se va a registrar como salido
          int room = getRoomNumber();
          // Registra la salida del huésped
          checkOut(hotel, room);
          break;
        }
      case 3:
        // Muestra la lista de huéspedes actuales en el hotel
        listGuests(hotel);
        break;
      case 4:
        // Finaliza el programa
        return 0;
      default:
        // Opción inválida
        throw runtime_error("Opción inválida.");
      }
    } catch (const exception& e) {
      // Muestra un mensaje de error en caso de que ocurra algún problema
      cerr << e.what() << endl;
    }
  }
}
