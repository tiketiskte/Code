class Animal():
    def __init__(self, name):
        self.name = name
    def greet(self):
        print("Hello, I am an %s." %self.name)
class Dog(Animal):
    def greet(self):
        print("wangwang..., I am an %s." %self.name)
class Cat(Animal):
    def greet(self):
        print("MiaoMiao..., I am an %s." %self.name)