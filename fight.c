#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define MAX_NAME_SIZE 12
#define NUM_OF_CHARACTERS 3

#define NUM_OF_STATS 3
#define STRENGTH_INDEX 0
#define DEXTERITY_INDEX 1
#define CHARISMA_INDEX 2

#define NUM_OF_RACES 4
#define HUMAN 0
#define ORC 1
#define ELF 2
#define UNDEAD 3

#define NUM_OF_CLASSES 5
#define NONE 0
#define WARRIOR 1
#define WIZARD 2
#define BARD 3
#define ASSASSIN 4

#define PLAYER_NAME "Conan"
#define PLAYER_RACE HUMAN
#define PLAYER_CLASS WARRIOR

#define PLAYER_STRENGTH 20
#define PLAYER_DEXTERITY 10
#define PLAYER_CHARISMA 5


#define set_character_stat(_character_ptr, _stat_index, _value)  (_character_ptr)->stat[_stat_index] =  _value

#define set_character_name(_character_ptr, _name)  strcpy((_character_ptr)->name,_name)
#define set_character_race(_character_ptr, _race)  (_character_ptr)->race =  _race
#define set_character_class(_character_ptr, _class)  (_character_ptr)->class =  _class

#define increase_character_strength(_character_ptr, _stat_index)  ++(character_ptr)->stat[_stat_index]

#define decrease_character_strength(_character_ptr, _stat_index)  --(character_ptr)->stat[_stat_index]

char *race_names[NUM_OF_RACES] = {
    "human", "orc", "elf", "undead"
};

char *class_names[NUM_OF_CLASSES] = {
    "none", "warrior", "wizard", "bard", "assassin"
};



char *stats_names[NUM_OF_STATS] = {
    "strength", "dexterity", "charisma"
};

// int player_stats[NUM_OF_STATS] = {50,45,10};


struct CharacterStruct 
{
    uint8_t stat[NUM_OF_STATS];
    
    uint8_t race;
    uint8_t class;
    char name[MAX_NAME_SIZE];
};
typedef struct CharacterStruct Character;


Character characters[NUM_OF_CHARACTERS];

// Character player;

char *characters_names[NUM_OF_CHARACTERS] = 
{
    "Conan",
    "Ulrik", 
    "Tondor"
};


uint8_t characters_races[NUM_OF_CHARACTERS] = 
{
    HUMAN, ORC, ELF
};

uint8_t characters_classes[NUM_OF_CHARACTERS] = 
{
    NONE, WARRIOR, ASSASSIN 
};


uint8_t characters_stats[NUM_OF_CHARACTERS][NUM_OF_STATS] =
{
    {
        50,55,10
    },
    {
        20,25,5
    },
    {
        40,10,2
    }
};



void initNames(void)
{
    uint8_t i;
    
    for(i=0;i<NUM_OF_CHARACTERS;++i)
    {
        memcpy(&characters[i].name,characters_names[i],MAX_NAME_SIZE);
    }
}

void initRaces(void)
{
    uint8_t char_index;
    
    for(char_index=0;char_index<NUM_OF_CHARACTERS;++char_index)
    {
        set_character_race(&characters[char_index], characters_races[char_index]);
    }
}


void initClasses(void)
{
    uint8_t char_index;
    
    for(char_index=0;char_index<NUM_OF_CHARACTERS;++char_index)
    {
        set_character_class(&characters[char_index], characters_classes[char_index]);
    }
}


void initFeatures(void)
{
    uint8_t char_index;
    uint8_t stat_index;
    
    for(char_index=0;char_index<NUM_OF_CHARACTERS;++char_index)
    {
        for(stat_index=0;stat_index<NUM_OF_STATS;++stat_index)
        {
            set_character_stat(&characters[char_index], stat_index, characters_stats[char_index][stat_index]);
        }
    }
}


void initCharacters(void)
{
    initNames();
    initRaces();
    initClasses();
    initFeatures();
}


void showCharacter (const Character* character_ptr)
{
    uint8_t stat_index;
    
    printf("\n");
    printf("Name: %s\n", character_ptr->name);
    printf("Race: %s\n", race_names[character_ptr->race]);
    printf("Class: %s\n", class_names[character_ptr->class]);
    
    for(stat_index = 0; stat_index<NUM_OF_STATS; ++stat_index)
    {
        printf("%s: %u\n", stats_names[stat_index], character_ptr->stat[stat_index]);
    }
    printf("\n");
}


void showCharacters(void)
{
    uint8_t i;
    
    for(i=0;i<NUM_OF_CHARACTERS;++i)
    {
        showCharacter(&characters[i]);
    }
}


// void initPlayer(void)
// {
    // uint8_t stat_index;
    
    // for(stat_index=0;stat_index<NUM_OF_STATS;++stat_index)
    // {
        // set_character_stat(&player, stat_index, player_stats[stat_index]);
    // }
    // set_character_name(&player, PLAYER_NAME);
    // set_character_race(&player, PLAYER_RACE);
    // set_character_class(&player, PLAYER_CLASS);
// }

int main(void)
{

    // initPlayer();

    initCharacters();
    
    // showCharacter(&player);
    
    showCharacters();

    return EXIT_SUCCESS;
}

