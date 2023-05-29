# ************************************************
# username    :   smmehrab
# fullname    :   s.m.mehrabul islam
# email       :   mehrab.24csedu.001@gmail.com
# institute   :   university of dhaka, bangladesh
# session     :   2017-2018
# ************************************************

class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.capacity = {
            1: big,
            2: medium,
            3: small
        }

    def addCar(self, carType: int) -> bool:
        if self.capacity[carType] > 0:
            self.capacity[carType] -= 1
            return True
        return False

# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)