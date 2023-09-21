import Animal

def Hello(animal):
    animal.greet()

dog = Animal.Dog("sjy")
Hello(dog)
cat = Animal.Cat("wsq")
Hello(cat)