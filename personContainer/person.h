#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <vector>
#include <unordered_map>

namespace person {

class Person {
    public:
        std::string name;
        std::string surname;
        int age;
        std::string city;
        long long pesel;

        Person() = default;

        Person(const std::string& _name, const std::string& _surname, const std::string & _city,
               const int _age, const long long _pesel):
            name(_name), surname(_surname), city(_city), age(_age), pesel(_pesel){};

        friend std::ostream& operator<< (std::ostream& stream,const Person & person)
        {
            stream << person.name << " " << person.surname << " from " << person.city << ", age "
              << person.age << ", PESEL number: " << person.pesel;
            return stream;
        };
};

bool operator==(const Person& lhs, const Person& rhs) {
    return (lhs.name == rhs.name) &&
           (lhs.age == rhs.age) &&
           (lhs.pesel == rhs.pesel);
}

struct PersonHash
{
    std::size_t operator()(Person const& p) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(p.name);
        std::size_t h2 = std::hash<int>{}(p.age);
        std::size_t h3 = std::hash<long long>{}(p.pesel);
        return h1 ^ (h2 > 1) ^ (h3 > 2);
    }
};

static Person get_random_person()
{
    std::vector<std::string> names{"Tomek", "Marcin", "Ania", "Marcin", "Agnieszka", "Maciej", "Władysław", 
                                    "Tomasz", "Damian", "Kleofas", "Gniewko", "Marianna" };
                                    
    std::vector<std::string> surnames{"Koryto", "Drewutnia", "Denko", "Podeszwa", 
                                    "Roman", "Kopytko", "Kartofel", "Pien", "Kowalski", "Szulc", "Czarny", 
                                    "Niebieski", "Podobny" };
    std::vector<std::string> cities { "Warszawa", "Krakow", "Lodz", "Wrocław", "Poznan", "Gdansk", "Szczecin",
                                     "Bydgoszcz", "Lublin", "Białystok", "Katowice"};
    Person p( names[std::rand()%names.size()], surnames[std::rand()%surnames.size()],
              cities[std::rand()%cities.size()], std::rand()%90, std::rand());
    return p;
}

} //namespace person

#endif 
