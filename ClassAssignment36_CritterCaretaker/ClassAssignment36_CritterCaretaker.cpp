
#include <iostream>

class Critter {
public:
    Critter(int hunger, int boredom);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
private:
    int GetMood() const;
    void PassTime(int time = 1);
    int m_Hunger;
    int m_Boredom;

};

Critter::Critter(int hunger, int boredom):
    m_Hunger(hunger),
    m_Boredom(boredom)
{ std::cout << "Critter born!\n"; }

void Critter::Talk() {
    std::cout << "Im feeling ";
    int mood = GetMood();
    if (mood > 15) {
        std::cout << "pretty upset honestly..\n";
    }
    else if (mood > 10) {
        std::cout << "meh.. I've had better days\n";
    }
    else if (mood > 5) {
        std::cout << "alright.\n";
    }
    else {
        std::cout << "happy! Im fine!\n";
    }

    PassTime();
}

void Critter::Eat(int food) {
    m_Hunger -= food;
    std::cout << "Yummy! Thank you!\n";
}

void Critter::Play(int fun) {
    m_Boredom -= fun;
    std::cout << "Haha! Yay that was fun!\n";
}

int Critter::GetMood() const {
    return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time){
    m_Hunger += time;
    m_Boredom += time;
}

int main()
{
    Critter critter(0, 0);
    critter.Talk();

    int choice;

    do {
        std::cout << "Creature Caretaker\n";
        std::cout << "0 = Quit\n";
        std::cout << "1 = Listen to your critter\n";
        std::cout << "2 = Feed your critter\n";
        std::cout << "3 = Play with your critter\n\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            critter.Talk();
            break;
        case 2:
            critter.Eat();
            break;
        case 3:
            critter.Play();
            break;
        default:
            std::cout << "Sorry. " << choice << " is not a valid choice, friend!\n";
        }

    } while (choice != 0);
}
