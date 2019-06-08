#ifndef __PERSON_H_
#define __PERSON_H_

#include <iostream>
#include <vector>
#include <unordered_map>

namespace person {

struct Person 
{    
    std::string name {}; 
    std::string surname {};
    int age {0};
    std::string city {};
    long long pesel {0};

    Person() = default;
    Person(const std::string& _name, const std::string& _surname, const std::string & _city,
           const int _age, const long long _pesel):
           name(_name), surname(_surname), age(_age), city(_city), pesel(_pesel){};
    
    friend std::ostream& operator<< (std::ostream& stream,const Person & person)
    {
        stream << person.name << " " << person.surname << " from " << person.city << ", age "
          << person.age << ", PESEL number: " << person.pesel;
        return stream;
    };
    bool operator < ( const Person& rhs ) const
    {
        return (this->pesel < rhs.pesel);
    };


};


bool operator==(const Person& lhs, const Person& rhs) 
{
    return (lhs.name == rhs.name) &&
       (lhs.age == rhs.age) &&
       (lhs.pesel == rhs.pesel);
}

struct PersonHash
{
    std::size_t operator()(Person const& p) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}( p.name );
        std::size_t h2 = std::hash<int>{}( p.age );
        std::size_t h3 = std::hash<long long>{}( p.pesel );
        std::size_t h4 = std::hash<std::string>{}( p.city );
        std::size_t h5 = std::hash<std::string>{}( p.surname );
        return h1 ^ ( h2 > 1 ) ^ ( h3 > 2 ) ^ ( h4 > 3 ) ^ ( h5 > 4 );
    }
};

static Person get_random_person()
{
    std::vector<std::string> names{"Teofil", "Marcin", "Anna", "Marcin", "Agnieszka", "Maciej", "Władysław", 
                                    "Tomasz", "Damian", "Kleofas", "Gniewko", "Marianna", "Mariola",
                                    "Radosław", "Urszula", "Iwona", "Maria" };
                                    
    std::vector<std::string> surnames{"Koryto", "Drewutnia", "Denko", "Podeszwa", "Deska", "Rower", "Wiadro",
                                    "Roman", "Kopytko", "Kartofel", "Pień", "Kowalski", "Szulc", "Czarny", 
                                    "Niebieski", "Podobny", "Śruba", "Węgiel", "Stołek", "Krzesło" };
    std::vector<std::string> cities { "Warszawa", "Kraków", "Lódź", "Wrocław", "Poznań", "Gdańsk", "Szczecin",
                                     "Bydgoszcz", "Lublin", "Białystok", "Katowice" };
    Person p( names[ std::rand()%names.size()], surnames[std::rand()%surnames.size() ],
              cities[ std::rand()%cities.size()], std::rand()%90, std::rand() );
    return p;
}

} //namespace person

#endif 
