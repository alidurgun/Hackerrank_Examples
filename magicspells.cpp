#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
    string scrollName;
public:
    Spell() : scrollName("") { }
    Spell(string name) : scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private: int power;
public:
    Fireball(int power) : power(power) { }
    void revealFirepower() {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private: int power;
public:
    Frostbite(int power) : power(power) { }
    void revealFrostpower() {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private: int power;
public:
    Thunderstorm(int power) : power(power) { }
    void revealThunderpower() {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private: int power;
public:
    Waterbolt(int power) : power(power) { }
    void revealWaterpower() {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;
    static string read() {
        return journal;
    }
};
string SpellJournal::journal = "";

void counterspell(Spell* spell) {

    try
    {
        Fireball* fireType = dynamic_cast<Fireball*>(spell);
        if (fireType != nullptr)
        {
            fireType->revealFirepower();
            return;
        }

        Frostbite* frostType = dynamic_cast<Frostbite*>(spell);
        if (frostType != nullptr)
        {
            frostType->revealFrostpower();
            return;
        }

        Thunderstorm* thunderType = dynamic_cast<Thunderstorm*>(spell);
        if (thunderType != nullptr)
        {
            thunderType->revealThunderpower();
            return;
        }

        Waterbolt* waterType = dynamic_cast<Waterbolt*>(spell);
        if (waterType != nullptr)
        {
            waterType->revealWaterpower();
            return;
        }

        // my longest-common-subsequence algorithm
        // casted spell name.
        string castedSpell = spell->revealScrollName();
        int castedSpellSize = castedSpell.size();

        // known spell name.
        string mySpell = SpellJournal::read();
        int mySpellSize = mySpell.size();

        // create 2 vector with subtext size + 1.
        // initialize them with 0 value.
        vector<int> cur(mySpellSize + 1, 0);
        vector<int> prev(mySpellSize + 1, 0);

        for (int i = 1; i < castedSpellSize + 1; i++)
        {
            for (int j = 1; j < mySpellSize + 1; j++)
            {
                // there is a match
                if (castedSpell[i - 1] == mySpell[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                }
                else
                {
                    cur[j] = max(cur[j - 1], prev[j]);
                }
            }
            prev = cur;
        }
        cout << cur[mySpellSize] << endl;
    }
    catch (bad_cast& e)
    {
        cout << "exception occured" << endl;
    }

}

class Wizard {
public:
    Spell* cast() {
        Spell* spell;
        string s; cin >> s;
        int power; cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        }
        else if (s == "frost") {
            spell = new Frostbite(power);
        }
        else if (s == "water") {
            spell = new Waterbolt(power);
        }
        else if (s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell* spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}