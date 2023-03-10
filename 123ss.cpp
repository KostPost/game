#include <vector>
#include <string>
#include <algorithm> 
#include <iostream>

using namespace std;

class character
{
private:
    int damage;
    int hp;
    int mana;
    string name;
public:

    character(int hp, int damage, int mana, string name)
    {
        this->hp = hp;
        this->damage = damage;
        this->mana = mana;
        this->name = name;
    }

    void shadowraze(character &zxc)
    {
        int spellDamage = 40;
        int spellMana = 20;

        zxc.attack(spellDamage);

        getMana(spellMana);
    }

    void kailakila(character& zxc)
    {
        int spellDamage = 100;
        int spellMana = 60;

        zxc.attack(spellDamage);

        getMana(spellMana);
    }

    void getMana(int mana)
    {
        this->mana -= mana;
        cout << "\nMana " << name << " player = " << this->mana << endl;
    }

    void attack(int damage)
    {
        hp = hp - damage;
        cout << "\nHP " << name << " player = " << hp << endl;
    }

    int getDamage()
    {
        return damage;
    }

    void setMana(int mana)
    {
        this->mana -= mana;
    }

    string getName()
    {
        return name;
    }

    int getHP()
    {
        return hp;
    }
};

int endGam(int &game, character &first, character &second)
{
    if (first.getHP() <= 0 || second.getHP() <= 0)
    {
        game = 1;

        cout << "End";
        return game;
    }
    
}

void Turn(character &firstCharacter, character &secondCharacter)
{
    int i = 0, choice = 0, choiceAttack = 0, choiceSpell = 0;

    cout << "\n" << firstCharacter.getName() <<  " character make a choice";
    cout << "Choice" << "\nAttack = 1" << "\nSpell = 2\n\n";
    do {
        cin >> choiceAttack;
    } while (!(choiceAttack == 1 || choiceAttack == 2));

    if (choiceAttack == 1)
    {
        secondCharacter.attack(firstCharacter.getDamage());
    }

    else
    {
        cout << "\nChoice spell" << "\nspell1 = 1" << "\nspell2 = 2\n\n";
        do {
            cin >> choiceSpell;
        } while (!(choiceSpell == 1 || choiceSpell == 2));

        if (choiceSpell == 1)
        {
            firstCharacter.shadowraze(secondCharacter);
        }
        else
        {
            firstCharacter.kailakila(secondCharacter);
        }
    }
}



int main()
{
    setlocale(LC_ALL, "ru");
    character q1(80, 20, 150, "First");
    character q2(100, 20, 150, "Second");

    int endGame = 0, choice = 0, choiceAttack = 0, choiceSpell = 0;
    
    while (endGame < 1)
    {
       

        cout << endGame;
        if (choice % 2 == 0)
        {
            Turn(q1,q2);
        }
        else
        {
            Turn(q2,q1);
        }
        endGam(endGame, q1, q2);
    }




    cout << 2 % 2; // 0 не четное // 1 четное;
}
