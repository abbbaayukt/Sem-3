#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Room
{
    private:
    int Room_no;
    string Roomtype;
    bool isavailable;
    int capacity;
    int occupiedbeds;

public:
   Room(int number, const string& type, int capacity)
   : Room_no(number), Roomtype(type), isavailable(true), capacity(capacity), occupiedbeds(0) {}

   int getRoomNumber() const { return Room_no; }
    string getRoomType() const { return Roomtype; }
    bool getAvailability() const { return isavailable; }
    int getOccupiedBeds() const { return occupiedbeds; }
    int getCapacity() const { return capacity; }

};

class Bed
{
    private:
    int bedId;
    bool isoccupied;

public:
   Bed(int id) : bed(id), isoccupied(false) {}

    int getBedId() const { return bedId; }
    bool getoccupiedStatus() const { return isoccupied; }

    void occupyBed() { isoccupied = true; }
    void releaseBed() { isoccupied = false; }

};

class RoomManager {
private:
    vector<Room> rooms;
    map<int, vector<Bed>> beds;

    public:

    void addRoom(int roomNumber, const string& roomType, int capacity) {
        rooms.emplace_back(roomNumber, roomType, capacity);
    }

    Room* findAvailableRoom(const string& roomType) {
        for (auto& room : rooms) {
            if (room.getRoomType() == roomType && room.getAvailability()) {
                return &room;
            }
        }
        return nullptr; 
    }

    bool assignRoomToPatient(int roomNumber) {
        for (auto& room : rooms) {
            if (room.getRoomNumber() == roomNumber && room.getAvailability()) {
                return room.addPatient(); 
            }
        }
        return false;
    }

    bool releaseRoom(int roomNumber) {
        for (auto& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {
                return room.removePatient(); 
            }
        }
        return false;
    }
};

int main(){
    return 0;
}