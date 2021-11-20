#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map <string, int> pokemon;
    string buffer;


    pokemon.insert(make_pair("ef", 2));
    pokemon.insert(make_pair("dc", 2));
    pokemon.insert(make_pair("ab", 2));
    pokemon.insert(make_pair("gh", 2));

    for (auto const& entry: pokemon)
    {
        std::cout << entry.second << " (" << entry.first << " of Earth's radius)" << '\n';
    }

    map<string, int> reverse_iterator ;


}
