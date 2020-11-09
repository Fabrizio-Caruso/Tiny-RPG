#include <stdio.h>
#include <string.h>

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
    Character *player_ptr = &player;
    
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


/*
int main(void)
{
    Character foo;
    
    strcpy(foo.name,"FooBar");
    foo.stat[LIFE] = 42;
    foo.stat[STAMINA] = 43;
    foo.stat[STRENGTH] = 44;
    foo.stat[DEXTERITY] = 45;
    
    while(1)
    {
        printf("\n");
        showFightStats(&foo);
        // printf("Hello %s\n", "world");
        getchar();
    }
	return 0;
}
*/

