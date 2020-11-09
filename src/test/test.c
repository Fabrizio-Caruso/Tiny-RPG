#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX_NAME_SIZE 20
#define NUM_OF_CHARACTERS 3

#define NUM_OF_STATIC_STATS 2
#define RACE 0
#define CLASS 1


#define NUM_OF_DYNAMIC_STATS 8
#define LIFE         (NUM_OF_STATIC_STATS+0)
#define STRENGTH     (NUM_OF_STATIC_STATS+1)
#define DEXTERITY    (NUM_OF_STATIC_STATS+2)
#define CHARISMA     (NUM_OF_STATIC_STATS+3)
#define EXPERIENCE   (NUM_OF_STATIC_STATS+4)
#define STAMINA      (NUM_OF_STATIC_STATS+5)
#define MANA         (NUM_OF_STATIC_STATS+6)
#define GOLD         (NUM_OF_STATIC_STATS+7)

#define NUM_OF_STATS (NUM_OF_STATIC_STATS + NUM_OF_DYNAMIC_STATS)

#define NUM_OF_RACES 3
#define HUMAN 0
#define ORC 1
#define ELF 2

#define NUM_OF_CLASSES 5
#define NONE 0
#define WARRIOR 1
#define WIZARD 2
#define BARD 3
#define ASSASSIN 4

#define LEADER 0
#define MAX_PLAYER_PARTY_SIZE 6
#define MAX_ENEMY_PARTY_SIZE 12
#define MAX_ORCS_SIZE 8 
#define MAX_HUMANS_SIZE 8
#define MAX_ELFS_SIZE 8


#define set_stat(_character_ptr, _stat_index, _value)  (_character_ptr)->stat[_stat_index] =  _value

#define set_race(_character_ptr, _value)          (_character_ptr)->stat[RACE] =  _value
#define set_class(_character_ptr, _value)         (_character_ptr)->stat[CLASS] =  _value
#define set_life(_character_ptr, _value)          (_character_ptr)->stat[LIFE] =  _value
#define set_strength(_character_ptr, _value)      (_character_ptr)->stat[STRENGTH] =  _value
#define set_dexterity(_character_ptr, _value)     (_character_ptr)->stat[DEXTERITY] =  _value
#define set_charisma(_character_ptr, _value)      (_character_ptr)->stat[CHARISMA] =  _value
#define set_experience(_character_ptr, _value)    (_character_ptr)->stat[EXPERIENCE] =  _value
#define set_stamina(_character_ptr, _value)       (_character_ptr)->stat[STAMINA] =  _value
#define set_mana(_character_ptr, _value)          (_character_ptr)->stat[MANA] =  _value
#define set_gold(_character_ptr, _value)          (_character_ptr)->stat[GOLD] =  _value


#define set_name(_character_ptr, _name)  strcpy((_character_ptr)->name,_name)

#define get_stat(_character_ptr, _stat_index) (_character_ptr)->stat[_stat_index]

#define get_name(_character_ptr) _character_ptr->name
#define get_life(_character_ptr) get_stat(_character_ptr,LIFE)
#define get_strength(_character_ptr) get_stat(_character_ptr,STRENGTH)
#define get_dexterity(_character_ptr) get_stat(_character_ptr,DEXTERITY)
#define get_stamina(_character_ptr) get_stat(_character_ptr,STAMINA)
#define get_experience(_character_ptr) get_stat(_character_ptr,EXPERIENCE)


struct CharacterStruct 
{
    uint8_t stat[NUM_OF_STATS];
    
    char name[MAX_NAME_SIZE];
};
typedef struct CharacterStruct Character;

Character* player_ptr;

void showFightStats(const Character* character_ptr)
{
    printf("\n");
    printf("%s - life: %u - stamina: %u - strength: %u - dexterity: %u\n", 
           character_ptr->name, 
           get_life(character_ptr), get_stamina(character_ptr),
           get_strength(character_ptr), get_dexterity(character_ptr));
    
}


int main(void)
{

    
    Character player;
    player_ptr = &player;
    
    set_name(player_ptr, "Conan");
    set_life(player_ptr, 42);
    set_strength(player_ptr,43);
    set_dexterity(player_ptr, 44);
    set_stamina(player_ptr,45);
    
    while(1)
    {
        showFightStats(player_ptr);
        getchar();
    }
    
    return 0;
}



