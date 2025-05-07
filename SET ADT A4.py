class SetADT:
    def __init__(self):
        self.elements = []

    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def display(self):
        print("Set elements:", self.elements)

    def search(self, element):
        return element in self.elements

    def iterator(self):
        return iter(self.elements)

    def size(self):
        return len(self.elements)

    def intersection(self, other_set):
        result = SetADT()
        for element in self.elements:
            if element in other_set.elements:
                result.add(element)
        return result

    def union(self, other_set):
        result = SetADT()
        for element in self.elements:
            result.add(element)
        for element in other_set.elements:
            result.add(element)
        return result

    def difference(self, other_set):
        result = SetADT()
        for element in self.elements:
            if element not in other_set.elements:
                result.add(element)
        return result

    def is_subset(self, other_set):
        for element in self.elements:
            if element not in other_set.elements:
                return False
        return True


# --- MENU-DRIVEN PROGRAM ---
def menu():
    set1 = SetADT()
    set2 = SetADT()

    while True:
        print("\n----- MENU -----")
        print("1. Add element to Set 1")
        print("2. Add element to Set 2")
        print("3. Remove element from Set 1")
        print("4. Remove element from Set 2")
        print("5. Display both sets")
        print("6. Search element in Set 1")
        print("7. Size of both sets")
        print("8. Union of sets")
        print("9. Intersection of sets")
        print("10. Difference (Set1 - Set2)")
        print("11. Is Set1 a subset of Set2?")
        print("12. Exit")
        choice = input("Enter your choice (1-12): ")

        if choice == '1':
            ele = int(input("Enter element to add to Set 1: "))
            set1.add(ele)
        elif choice == '2':
            ele = int(input("Enter element to add to Set 2: "))
            set2.add(ele)
        elif choice == '3':
            ele = int(input("Enter element to remove from Set 1: "))
            set1.remove(ele)
        elif choice == '4':
            ele = int(input("Enter element to remove from Set 2: "))
            set2.remove(ele)
        elif choice == '5':
            print("Set 1:")
            set1.display()
            print("Set 2:")
            set2.display()
        elif choice == '6':
            ele = int(input("Enter element to search in Set 1: "))
            print("Found in Set 1!" if set1.search(ele) else "Not found in Set 1.")
        elif choice == '7':
            print("Size of Set 1:", set1.size())
            print("Size of Set 2:", set2.size())
        elif choice == '8':
            result = set1.union(set2)
            print("Union:", list(result.iterator()))
        elif choice == '9':
            result = set1.intersection(set2)
            print("Intersection:", list(result.iterator()))
        elif choice == '10':
            result = set1.difference(set2)
            print("Difference (Set1 - Set2):", list(result.iterator()))
        elif choice == '11':
            print("Yes" if set1.is_subset(set2) else "No")
        elif choice == '12':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")

menu()
