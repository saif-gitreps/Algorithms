class ParkingSystem {
EASY LOL.
private:
vector<int> parking;

public:
    ParkingSystem(int big, int medium, int small): parking(4, 0) {
        this -> parking[1] = big;
        this -> parking[2] = medium;
        this -> parking[3] = small;
    }
    
    bool addCar(int carType) {
        if(this -> parking[carType]){
            this -> parking[carType] = this -> parking[carType] - 1;
            return true;
        }
        else{
            return false;
        }
    }
};
