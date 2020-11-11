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


#define NUM_OF_DYNAMIC_STATS 16
#define LIFE         (NUM_OF_STATIC_STATS+0)
#define STRENGTH     (NUM_OF_STATIC_STATS+1)
#define DEXTERITY    (NUM_OF_STATIC_STATS+2)
#define CHARISMA     (NUM_OF_STATIC_STATS+3)
#define EXPERIENCE   (NUM_OF_STATIC_STATS+4)
#define LEVEL        (NUM_OF_STATIC_STATS+5)
#define STAMINA      (NUM_OF_STATIC_STATS+6)
#define MANA         (NUM_OF_STATIC_STATS+7)
#define GOLD         (NUM_OF_STATIC_STATS+8)
#define SHIELD       (NUM_OF_STATIC_STATS+9)
#define BREASTPLATE  (NUM_OF_STATIC_STATS+10)
#define HELMET       (NUM_OF_STATIC_STATS+11)
#define BOOTS        (NUM_OF_STATIC_STATS+12)
#define MEDALLION    (NUM_OF_STATIC_STATS+13)
#define SWORD        (NUM_OF_STATIC_STATS+14)
#define POTIONS      (NUM_OF_STATIC_STATS+15)


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


#define set_base_base_stat(_character_ptr, _stat_index, _value)  (_character_ptr)->stat[_stat_index] =  _value

#define set_base_race(_character_ptr, _value)          (_character_ptr)->stat[RACE] =  _value
#define set_base_class(_character_ptr, _value)         (_character_ptr)->stat[CLASS] =  _value
#define set_base_life(_character_ptr, _value)          (_character_ptr)->stat[LIFE] =  _value
#define set_base_strength(_character_ptr, _value)      (_character_ptr)->stat[STRENGTH] =  _value
#define set_base_dexterity(_character_ptr, _value)     (_character_ptr)->stat[DEXTERITY] =  _value
#define set_base_charisma(_character_ptr, _value)      (_character_ptr)->stat[CHARISMA] =  _value
#define set_base_experience(_character_ptr, _value)    (_character_ptr)->stat[EXPERIENCE] =  _value
#define set_base_level(_character_ptr, _value)         (_character_ptr)->stat[LEVEL] =  _value
#define set_base_stamina(_character_ptr, _value)       (_character_ptr)->stat[STAMINA] =  _value
#define set_base_mana(_character_ptr, _value)          (_character_ptr)->stat[MANA] =  _value
#define set_base_gold(_character_ptr, _value)          (_character_ptr)->stat[GOLD] =  _value

#define set_base_shield(_character_ptr, _value)        (_character_ptr)->stat[SHIELD] =  _value
#define set_base_breastplate(_character_ptr, _value)   (_character_ptr)->stat[BREASTPLATE] =  _value
#define set_base_helmet(_character_ptr, _value)        (_character_ptr)->stat[HELMET] =  _value
#define set_base_sword(_character_ptr, _value)         (_character_ptr)->stat[SWORD] =  _value
#define set_base_boots(_character_ptr, _value)         (_character_ptr)->stat[BOOTS] =  _value
#define set_base_medallion(_character_ptr, _value)     (_character_ptr)->stat[MEDALLION] =  _value

#define set_base_potions(_character_ptr, _value)       (_character_ptr)->stat[POTIONS] =  _value


#define set_base_name(_character_ptr, _name)  strcpy((_character_ptr)->name,_name)

#define get_base_stat(_character_ptr, _stat_index) (_character_ptr)->stat[_stat_index]

#define get_base_name(_character_ptr) _character_ptr->name
#define get_base_race(_character_ptr) get_base_stat(_character_ptr,RACE)
#define get_base_class(_character_ptr) get_base_stat(_character_ptr,CLASS)
#define get_base_life(_character_ptr) get_base_stat(_character_ptr,LIFE)
#define get_base_strength(_character_ptr) get_base_stat(_character_ptr,STRENGTH)
#define get_base_dexterity(_character_ptr) get_base_stat(_character_ptr,DEXTERITY)
#define get_base_stamina(_character_ptr) get_base_stat(_character_ptr,STAMINA)
#define get_base_experience(_character_ptr) get_base_stat(_character_ptr,EXPERIENCE)


#define increase_base_stat(_character_ptr, _stat_index, _value)  ((_character_ptr)->stat[_stat_index])+=_value;

#define decrease_base_stat(_character_ptr, _stat_index, _value)  ((_character_ptr)->stat[_stat_index])-=_value;

#define increase_base_stamina(_character_ptr, _value) increase_base_stat(_character_ptr, STAMINA, _value)
#define increase_base_experience(_character_ptr, _value) increase_base_stat(_character_ptr, EXPERIENCE, _value)
#define decrease_base_stamina(_character_ptr, _value) decrease_base_stat(_character_ptr, STAMINA, _value)


#define CHARACTER_NAMES \
{ \
    "Conan", \
    "Ulrik", \
    "Sheewa" \
}

#define CONAN    0
#define ULRIK    1
#define SHEEWA   2

char *stats_names[NUM_OF_STATS] = {
//                  RACE      CLASS       LIFE      STRENGTH     DEXTERITY     CHARSIMA      EXPERIENCE      LEVEL    STAMINA      MANA     GOLD
                   "race",   "class",    "life",   "strength",  "dexterity",  "charisma",  "experience",    "level"   "stamina",   "mana",  "gold"};
#define CONAN_STATS       \
                    HUMAN,    NONE,        100,       30,           55,           10,            0,           1,           5,         10,       10,0,0,0,0,0,0,0
#define ULRIK_STATS       \
                    ORC,      WARRIOR,      80,       15,           10,            5,            0,           1,          20,         20,        5,0,0,0,0,0,0,0
#define SHEEWA_STATS      \
                    ELF,      ASSASSIN,     20,       10,           20,            2,            0,           1,          40,         40,       30,0,0,0,0,0,0,0

#define HUMAN_SOLDIER_STATS \
                    HUMAN,    WARRIOR,      10,       10,           10,           10,            0,           1,          15,         10,       10,0,0,0,0,0,0,0
#define ORC_SOLDIER_STATS \
                    ORC,      WARRIOR,      18,       12,           8,            10,            0,           1,          15,         10,       10,0,0,0,0,0,0,0

// #define VERBOSE_OFF 1
#define VERBOSE_OFF 0
#define VERBOSE_ON  1


#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif

void sleep_ms(int milliseconds){ // cross-platform sleep function
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#elif defined(__GCC__)
    if (milliseconds >= 1000)
      sleep(milliseconds / 1000);
    usleep((milliseconds % 1000) * 1000);
#else
    uint16_t i;
    for(i=1;i<milliseconds;++i){};
#endif
}

#define SLEEP(n) sleep_ms(10*n)

char *race_names[NUM_OF_RACES] = {
    "human", "orc", "elf"
};

char *class_names[NUM_OF_CLASSES] = {
    "none", "warrior", "wizard", "bard", "assassin"
};


struct CharacterStruct 
{
    uint8_t stat[NUM_OF_STATS];
    
    char name[MAX_NAME_SIZE];
};
typedef struct CharacterStruct Character;


Character *player_party[MAX_PLAYER_PARTY_SIZE];
uint8_t player_party_size;

Character *enemy_party[MAX_ENEMY_PARTY_SIZE];
uint8_t enemy_party_size;

Character *aux_party[MAX_ENEMY_PARTY_SIZE];


Character characters[NUM_OF_CHARACTERS];


#define STAMINA_RECHARGE 10
#define LOW_STAMINA_THRESHOLD 10
#define low_stamina(stamina) (stamina<LOW_STAMINA_THRESHOLD)

#define ATTACK_FACTOR_ADVANTAGE 2


Character orcs[MAX_ORCS_SIZE];
Character humans[MAX_HUMANS_SIZE];
Character elfs[MAX_ELFS_SIZE];



Character* conan_ptr = &characters[CONAN];

Character* ulrik_ptr = &characters[ULRIK];

Character* sheewa_ptr = &characters[SHEEWA];

Character* player_ptr;
Character* enemy_ptr;

char *characters_names[NUM_OF_CHARACTERS] = CHARACTER_NAMES;


uint8_t characters_stats[NUM_OF_CHARACTERS][NUM_OF_STATS] =
{
    {CONAN_STATS}, {ULRIK_STATS}, {SHEEWA_STATS}
};


typedef void (*ShowCharacterFunction) (const Character *);


void initNames(void)
{
    uint8_t i;
    
    for(i=0;i<NUM_OF_CHARACTERS;++i)
    {
        memcpy(&characters[i].name,characters_names[i],MAX_NAME_SIZE);
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
            set_base_base_stat(&characters[char_index], stat_index, characters_stats[char_index][stat_index]);
        }
    }
}


void initCharacters(void)
{
    initNames();
    initFeatures();
}


void showFightStats(const Character* character_ptr)
{
    printf("\n");
    printf("%s - life: %u - stamina: %u - strength: %u - dexterity: %u\n", 
           character_ptr->name, 
           get_base_life(character_ptr), get_base_stamina(character_ptr),
           get_base_strength(character_ptr), get_base_dexterity(character_ptr));
    
}


void showAllStats(const Character* character_ptr)
{
    uint8_t stat_index;
    
    printf("\n");
    printf("Name: %s\n", character_ptr->name);
    

    printf("%s: %s\n", stats_names[RACE], race_names[get_base_race(character_ptr)]);
    printf("%s: %s\n", stats_names[CLASS], class_names[get_base_class(character_ptr)]);

    
    for(stat_index=NUM_OF_STATIC_STATS; stat_index<NUM_OF_STATS; ++stat_index)
    {
        printf("%s: %u\n", stats_names[stat_index], get_base_stat(character_ptr,stat_index));
    }
    printf("\n");
}


void showParty(Character **party, uint8_t party_size, ShowCharacterFunction showCharacterFunction)
{
    uint8_t i;
    
    for(i=0;i<party_size;++i)
    {
        showCharacterFunction(party[i]);
        
        getchar();

    }
    printf("\n");
}


void blow(Character *defender_ptr, uint8_t value)
{
    if(get_base_life(defender_ptr)>value)
    {
        defender_ptr->stat[LIFE]-=value;
    }
    else
    {
        set_base_base_stat(defender_ptr,LIFE,0);
    }
}


uint8_t fight_stat(uint8_t stat_value, uint8_t stamina)
{
    return stat_value/(1+(rand()&3))/(1+low_stamina(stamina));
}


uint8_t _attack(Character *attacker_ptr, Character* defender_ptr)
{
    uint8_t attacker_stamina = get_base_stamina(attacker_ptr);
    uint8_t blow_hits = 0;
    
    if (ATTACK_FACTOR_ADVANTAGE*fight_stat(get_base_dexterity(attacker_ptr), attacker_stamina) >
        fight_stat(get_base_dexterity(defender_ptr), get_base_stamina(defender_ptr)))
    {
        blow_hits = fight_stat(get_base_strength(attacker_ptr), attacker_stamina);
        blow(defender_ptr, blow_hits);
    }
    decrease_base_stamina(attacker_ptr,1);

    return blow_hits;
}


void attack(Character *attacker_ptr, Character *defender_ptr, uint8_t verbose)
{
    uint8_t attack_force = _attack(attacker_ptr, defender_ptr);
    
    if(verbose)
    {
        if(attack_force)
        {
            printf("%s hits %s with force=%u\n", attacker_ptr->name, defender_ptr->name, attack_force);
        }
        else
        {
            printf("%s attacks but %s fends off the attack\n", attacker_ptr->name, defender_ptr->name);
        }
        SLEEP(1);
    }
}


void try_attack(Character *attacker_ptr, Character *defender_ptr, uint8_t verbose)
{
    uint8_t attacker_stamina = get_base_stamina(attacker_ptr);
    
    if((attacker_ptr==player_ptr) && (low_stamina(attacker_stamina)))
    {
        printf("%s has low stamina\n", get_base_name(player_ptr));
    }
    
    if(attacker_stamina)
    {
        attack(attacker_ptr, defender_ptr, verbose);
    }
    else
    {
        if((attacker_ptr==player_ptr)&&(attacker_ptr==enemy_ptr))
        {
            printf("%s recovers some stamina\n", get_base_name(attacker_ptr));
        }
        increase_base_stamina(attacker_ptr,STAMINA_RECHARGE);
    }
}


void fight_turn(Character* attacker_ptr, Character* defender_ptr, uint8_t verbose)
{
    try_attack(attacker_ptr, defender_ptr, verbose);

    if(!get_base_life(defender_ptr))
    {
        if(!verbose)
        {
            printf("\n");
        }
        printf("%s kills %s!\n\n", attacker_ptr->name, defender_ptr->name);
        increase_base_experience(attacker_ptr,1+get_base_experience(defender_ptr)/20);
    }
    

}

void fight_round(Character* first_ptr, Character* second_ptr, uint8_t verbose)
{

// TODO: DEBUG
// verbose = 1;
//
    fight_turn(first_ptr, second_ptr, verbose);
    if(get_base_life(second_ptr))
    {
        fight_turn(second_ptr, first_ptr, verbose);
    }
    if(verbose)
    {
        printf("\n");
    }
}



void many_vs_one_fight(Character *group_ptr, uint8_t enemy_number, Character *single_ptr)
{
    uint8_t i;
    
    for(i=0;i<enemy_number;++i)
    {
        if(get_base_life(group_ptr) && get_base_life(single_ptr))
        {
            fight_round(single_ptr, group_ptr, VERBOSE_ON);
        }
        else
        {
            break;
        }
        group_ptr +=1;
    }
}

void print_stamina_string(const Character *character_ptr)
{
    
    uint8_t character_stamina = get_base_stamina(character_ptr);
    
    if(!character_stamina)
    {
        printf("%s needs a stop to recover some stamina!\n\n", get_base_name(character_ptr));
    }
    else if(low_stamina(character_stamina))
        {
            printf("%s has low stamina\n\n", get_base_name(character_ptr));
        }
    SLEEP(1);
}


void party_fight(void)
{
    uint8_t min_size = MIN(player_party_size, enemy_party_size);
    uint8_t i;
    uint8_t round = 0;
    uint8_t verbose;
    
    while (get_base_life(player_ptr) && get_base_life(enemy_ptr))
    {
        printf("\n\n\n------------------\n");
        printf("round %u\n", ++round);
        printf(      "------------------\n");
        getchar();
        showFightStats(player_ptr);
        getchar();
        showFightStats(enemy_ptr);
        getchar();
        
        printf("\nFight!\n");
        getchar();
        
        fight_round(player_party[LEADER],enemy_party[LEADER], VERBOSE_ON);
        
        // printf("----------------------------------\n");
        
        if((get_base_life(player_ptr)) && (get_base_life(enemy_ptr)))
        {
            for(i=1;i<min_size;++i)
            {
                Character* player_party_member_ptr = player_party[i*(i && get_base_life(player_party[i]))];
                Character* enemy_party_member_ptr  = enemy_party[i*(i && get_base_life(enemy_party[i]))];
                verbose = !(get_base_life(player_party[i]) && get_base_life(enemy_party[i]));
                
                if(player_party_member_ptr!=player_ptr || enemy_party_member_ptr!=enemy_ptr)
                {
                    fight_round(player_party_member_ptr, enemy_party_member_ptr, verbose);
                }
            }
            printf("----------------------------------\n");

            if(player_party_size>min_size) // You have more party members
            {
                many_vs_one_fight(player_party[i], player_party_size-enemy_party_size, enemy_ptr);
            }
            else // The enemy party has more members
            {
                many_vs_one_fight(enemy_party[i], enemy_party_size - player_party_size, player_ptr);
            }
        }
    }
    
}



// "race",   "class",    "life",  "strength",  "dexterity",  "charisma",  "experience",  "stamina",   "mana",  "gold"};
void set_base_stats(Character *character_ptr, const char* name, uint8_t race, uint8_t class, 
               uint8_t life, uint8_t strength, uint8_t dexterity,
               uint8_t charisma, uint8_t experience, uint8_t level,
               uint8_t stamina, uint8_t mana, uint8_t gold,
               uint8_t shield, uint8_t breastplate, uint8_t helmet, 
               uint8_t sword, uint8_t boots, uint8_t medallion,
               uint8_t potions)
{
    set_base_name(character_ptr, name);
    set_base_race(character_ptr, race);
    set_base_class(character_ptr, class);
    
    set_base_life(character_ptr, life);
    set_base_strength(character_ptr, strength);
    set_base_dexterity(character_ptr, dexterity);
    set_base_charisma(character_ptr, charisma);
    set_base_experience(character_ptr, experience);
    set_base_level(character_ptr, level);
    
    set_base_stamina(character_ptr, stamina);
    set_base_mana(character_ptr, mana);
    set_base_gold(character_ptr, gold);
    
    set_base_shield(character_ptr, shield);
    set_base_breastplate(character_ptr, breastplate);
    set_base_helmet(character_ptr, helmet);
    
    set_base_sword(character_ptr, sword);
    set_base_boots(character_ptr, boots);
    set_base_medallion(character_ptr, medallion);

    set_base_potions(character_ptr, potions);
}


uint8_t removeDeadMembers(Character **party_ptr, uint8_t party_size)
{
    uint8_t i = 0;
    uint8_t new_size = 0;
    Character **search_ptr = party_ptr;
    
    
    while(i<party_size)
    {
        if(get_base_life(*search_ptr))
        {
            aux_party[new_size] = search_ptr[new_size];
            ++new_size;
        }
        ++i;
        ++search_ptr;
    }
    
    for(i=0;i<new_size;++i)
    {
        *(party_ptr+i) = aux_party[i];
    }
    
    return new_size;
    
}


void initPlayerParty(void)
{
    uint8_t i;

    char soldier_name[MAX_NAME_SIZE] = "your soldier ( )";
     //                                 012345678901234567
     
    player_party[LEADER] = conan_ptr;
    player_party_size = 3;

    for(i=1;i<player_party_size;++i)
    {
        soldier_name[14] = '0'+i; //soldier_name
        set_base_stats(&humans[i-1], soldier_name, HUMAN_SOLDIER_STATS);
        player_party[i] = &humans[i-1];
    }
    
}

void initEnemyParty(void)
{
    uint8_t i;

    char soldier_name[MAX_NAME_SIZE] = "an enemy orc ( )";
     //                                 012345678901234567
    enemy_party[LEADER] = ulrik_ptr;
    enemy_party_size = 8;

    for(i=1;i<enemy_party_size;++i)
    {
        soldier_name[14] = '0'+i; //soldier_name
        set_base_stats(&orcs[i-1],soldier_name, ORC_SOLDIER_STATS);
        enemy_party[i] = &orcs[i-1];
    }

}


int main(void)
{
    
    Character *winner_ptr;
   

    initCharacters();
    
    initPlayerParty();
    initEnemyParty();
   
    player_ptr = player_party[LEADER];
    enemy_ptr = enemy_party[LEADER];
   
    // showAllStatsForAllCharacters();
    showParty(player_party, player_party_size, showFightStats);
    
    getchar();
    
    showParty(enemy_party, enemy_party_size, showFightStats);

    
    getchar();
    
    party_fight();
    
    getchar();
    printf("\n\n");
    printf("-------------\n\n");
    if(get_base_life(player_party[LEADER]))
    {
        winner_ptr = player_party[LEADER];
    }
    else
    {
        winner_ptr = enemy_party[LEADER];
    }
    printf("\n%s wins!\n", winner_ptr->name);
    getchar();
    printf("\n\n");
    printf("-------------\n\n");

    
    showParty(enemy_party, enemy_party_size, showFightStats);
    
    //enemy_party_size = 
    enemy_party_size = removeDeadMembers(enemy_party, enemy_party_size);
    
    printf("\n\n");
    
    // printf("DEBUG\n");
    // showParty(aux_party, enemy_party_size, showFightStats);

    printf("After removal\n");
    
    
    showParty(enemy_party, enemy_party_size, showFightStats);
    

    return EXIT_SUCCESS;
}



