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


#define MARKET_DISTANCE 5
#define EASY_QUEST_DISTANCE 3
#define HARD_QUEST_DISTANCE 6
#define FINAL_QUEST_DISTANCE 9


#define set_base_stat(_character_ptr, _stat_index, _value)  (_character_ptr)->stat[_stat_index] =  _value

#define set_leader(_character_ptr,_leader_ptr) (_character_ptr)->leader_ptr = _leader_ptr

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
#define get_base_charisma(_character_ptr) get_base_stat(_character_ptr,CHARISMA)
#define get_base_stamina(_character_ptr) get_base_stat(_character_ptr,STAMINA)
#define get_base_experience(_character_ptr) get_base_stat(_character_ptr,EXPERIENCE)

#define get_base_level(_character_ptr) get_base_stat(_character_ptr,LEVEL)
#define get_base_mana(_character_ptr) get_base_stat(_character_ptr,MANA)
#define get_base_gold(_character_ptr) get_base_stat(_character_ptr,GOLD)
#define get_base_shield(_character_ptr) get_base_stat(_character_ptr,SHIELD)
#define get_base_brestplate(_character_ptr) get_base_stat(_character_ptr,BREASTPLATE)
#define get_base_helmet(_character_ptr) get_base_stat(_character_ptr,HELMET)
#define get_base_sword(_character_ptr) get_base_stat(_character_ptr,SWORD)
#define get_base_boots(_character_ptr) get_base_stat(_character_ptr,BOOTS)
#define get_base_medallion(_character_ptr) get_base_stat(_character_ptr,MEDALLION)
#define get_base_potions(_character_ptr) get_base_stat(_character_ptr,POTIONS)

#define get_name(_character_ptr) get_base_name(_character_ptr)
#define get_race(_character_ptr) get_base_race(_character_ptr)

#define get_strength(_character_ptr) get_stat(_character_ptr,STRENGTH)
#define get_dexterity(_character_ptr) get_stat(_character_ptr,DEXTERITY)

#define get_class(_character_ptr) get_stat(_character_ptr,CLASS)
#define get_life(_character_ptr) get_stat(_character_ptr,LIFE)
#define get_charisma(_character_ptr) get_stat(_character_ptr,CHARISMA)
#define get_stamina(_character_ptr) get_stat(_character_ptr,STAMINA)
#define get_experience(_character_ptr) get_stat(_character_ptr,EXPERIENCE)


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


#define get_leader_charisma_bonus(_character_ptr) (get_leader_charisma(_character_ptr)/10)


#define STAMINA_RECHARGE 10
#define LOW_STAMINA_THRESHOLD 12

#define low_stamina(stamina) ((stamina)<LOW_STAMINA_THRESHOLD)

#define ATTACK_FACTOR_ADVANTAGE 2

#define is_fight_stat(_stat_index) ((_stat_index)==STRENGTH)||((_stat_index)==DEXTERITY)

// #define VERBOSE_OFF 1
#define VERBOSE_OFF 0
#define VERBOSE_ON  1



#ifdef _WIN32
#define clrscr() system("cls");
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif


#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>   // for nanosleep
#else
#include <unistd.h> // for usleep
#endif


// // --------------------------------------------------------------------------------------------------------

// Character struct
struct CharacterStruct 
{
    uint8_t stat[NUM_OF_STATS];
    
    char name[MAX_NAME_SIZE];
    
    struct CharacterStruct* leader_ptr;
};
typedef struct CharacterStruct Character;

// --------------------------------------------------------------------------------------------------------
// Display function typedef
typedef void (*ShowCharacterFunction) (const Character *);


// --------------------------------------------------------------------------------------------------------
// Variable initialization

#define ULRIK_LIFE 80

const char *stats_names[NUM_OF_STATS] = {
//                  RACE      CLASS       LIFE      STRENGTH     DEXTERITY     CHARSIMA      EXPERIENCE      LEVEL    STAMINA      MANA     GOLD
                   "race",   "class",    "life",   "strength",  "dexterity",  "charisma",  "experience",    "level",   "stamina",   "mana",  "gold",
                   "shield","breastplate","helmet","sword","boots","medallion","potions"};
#define CONAN_STATS       \
                    HUMAN,    NONE,        100,       30,           55,           90,            0,           1,           5,         10,       10, \
                    0,       0,            0,        0,      0,      0,          0
#define ULRIK_STATS       \
                    ORC,      WARRIOR,     ULRIK_LIFE,       15,           10,            5,            0,           1,          20,         20,        5, \
                    0,       0,            0,        0,      0,      0,          0
#define SHEEWA_STATS      \
                    ELF,      ASSASSIN,     20,       10,           20,            2,            0,           1,          40,         40,       30, \
                    0,       0,            0,        0,      0,      0,          0
#define HUMAN_SOLDIER_STATS \
                    HUMAN,    WARRIOR,      10,       10,           10,           10,            0,           1,          15,         10,       10, \
                    0,       0,            0,        0,      0,      0,          0
#define ORC_SOLDIER_STATS \
                    ORC,      WARRIOR,      18,       12,           8,            10,            0,           1,          15,         10,       10, \
                    0,       0,            0,        0,      0,      0,          0


const char *race_names[NUM_OF_RACES] = {
    "human", "orc", "elf"
};

const char *class_names[NUM_OF_CLASSES] = {
    "none", "warrior", "wizard", "bard", "assassin"
};


Character *player_party[MAX_PLAYER_PARTY_SIZE];
uint8_t player_party_size;

Character aux_player_party[MAX_PLAYER_PARTY_SIZE];

Character *enemy_party[MAX_ENEMY_PARTY_SIZE];
uint8_t enemy_party_size;

Character *aux_party[MAX_ENEMY_PARTY_SIZE];


Character characters[NUM_OF_CHARACTERS];


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

enum Location {INN, SQUARE, WAY_THERE, WAY_BACK, EASY_QUEST, HARD_QUEST, FINAL_QUEST, MARKET};

enum Location player_location;

uint8_t quest_week;

uint8_t adventure_week;

char selection;

uint8_t destination_distance;

enum Location destination;

// --------------------------------------------------------------------------------------------------------
// Getters and Setters funtcions
uint8_t get_leader_charisma(const Character* character_ptr)
{
    if(character_ptr->leader_ptr)
    {
        return get_base_charisma(character_ptr->leader_ptr);
    }
    else
    {
        // printf("\n[error]: No leader found\n");
        return 0;
    }
}


uint8_t get_stat(const Character* character_ptr, uint8_t stat_index)
{
    uint8_t res = get_base_stat(character_ptr,stat_index);
    
    if(is_fight_stat(stat_index))
    {
        res+= get_leader_charisma_bonus(character_ptr);
    }
    return res;
}


uint8_t get_armor(const Character* character_ptr)
{
    return get_base_helmet(character_ptr)+get_base_brestplate(character_ptr)+get_base_shield(character_ptr);
}


// --------------------------------------------------------------------------------------------------------
// Cross-platform sleep function
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

#define SLEEP(n) sleep(1)
//sleep_ms(500*n)


// --------------------------------------------------------------------------------------------------------
// Display functions

void showFightStats(const Character* character_ptr)
{
    printf("\n----DEBUG showFightStats----\n");
    
    printf("\n");
    printf("%s - life: %u - stamina: %u - strength: %u + %u - dexterity: %u + %u - armor: %u\n", 
           character_ptr->name, 
           get_base_life(character_ptr), get_base_stamina(character_ptr),
           get_base_strength(character_ptr), get_leader_charisma_bonus(character_ptr),
           get_dexterity(character_ptr), get_leader_charisma_bonus(character_ptr),
           get_armor(character_ptr)
           );
    
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
        if(is_fight_stat(stat_index))
        {
            printf("%s: %u + %u\n", stats_names[stat_index], get_stat(character_ptr,stat_index), get_leader_charisma_bonus(character_ptr));
        }
        else
        {
            printf("%s: %u\n", stats_names[stat_index], get_stat(character_ptr,stat_index));
        }
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



// --------------------------------------------------------------------------------------------------------
// Fight functions

void blow(Character *defender_ptr, uint8_t value)
{
    if(get_base_life(defender_ptr)>value)
    {
        defender_ptr->stat[LIFE]-=value;
    }
    else
    {
        set_base_stat(defender_ptr,LIFE,0);
    }
}


uint8_t fight_stat(uint8_t stat_value, uint8_t stamina)
{
    return stat_value/(1+(rand()&3))/(1+low_stamina(stamina));
}


uint8_t _attack(Character *attacker_ptr, Character* defender_ptr, uint8_t attacker_stamina)
{
    uint8_t blow_hits = 0;
    
    if (ATTACK_FACTOR_ADVANTAGE*fight_stat(get_base_dexterity(attacker_ptr), attacker_stamina) >
        fight_stat(get_base_dexterity(defender_ptr), get_base_stamina(defender_ptr)))
    {
        uint8_t defender_armor = get_armor(defender_ptr);
        blow_hits = fight_stat(get_base_strength(attacker_ptr), attacker_stamina);
        if(blow_hits<defender_armor+1)
        {
            blow_hits=1;
        }
        else
        {
            blow_hits -= defender_armor;
        }
        blow(defender_ptr, blow_hits);
    }
    decrease_base_stamina(attacker_ptr,1);

    return blow_hits;
}


void attack(Character *attacker_ptr, Character *defender_ptr, uint8_t attacker_stamina, uint8_t verbose)
{
    uint8_t attack_force = _attack(attacker_ptr, defender_ptr, attacker_stamina);
    
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
        getchar();
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
        attack(attacker_ptr, defender_ptr, attacker_stamina, verbose);
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



void many_vs_one_fight(Character *group_ptr, uint8_t group_size, Character *single_ptr)
{
    uint8_t i;
    
    for(i=0;i<group_size;++i)
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

void apply_stamina_bonus(Character** party, uint8_t party_size)
{
    uint8_t i;
    
    for(i=1;i<party_size;++i)
    {
        // printf("\nDEBUG) increase stamina %d\n",i);
        increase_base_stamina(party[i], get_leader_charisma_bonus(party[i]));
        // printf("\nDEBUG) DONE increase stamina %d\n",i);

    }
}

uint8_t party_speed(Character** party_ptr, uint8_t party_size)
{
    uint8_t i;
    uint8_t r = 0;
    
    for(i=0;i<party_size;++i)
    {
        r+=get_dexterity(party_ptr[i]);
    }
    return r/=party_size;
}

uint8_t party_escape(void)
{
    return (party_speed(player_party, player_party_size)>party_speed(enemy_party, enemy_party_size));
}


void party_fight(void)
{
    uint8_t min_size = MIN(player_party_size, enemy_party_size);
    uint8_t i;
    uint8_t round = 0;
    uint8_t verbose;
    
    apply_stamina_bonus(player_party, player_party_size);
    apply_stamina_bonus(enemy_party, enemy_party_size);
    
    printf("\n**************DEBUG*************** after apply stamina\n");
    
    // DEBUG
    // showParty(player_party, player_party_size, showFightStats);
    showParty(enemy_party, enemy_party_size, showFightStats);
    
    if(get_base_life(player_ptr))
    {
        printf("PLAYER BASE LIFE OK\n");
    }
    
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
        
        // Start a fight round between the player leader and the enemy leader
        fight_round(player_party[LEADER],enemy_party[LEADER], VERBOSE_ON);
        
        // printf("----------------------------------\n");
        
        if((get_base_life(player_ptr)) && (get_base_life(enemy_ptr)))
        {
            for(i=1;i<min_size;++i)
            {
                // Select the i-th player party member if alive, otherwise select player leader
                Character* player_party_member_ptr = player_party[i*(i && get_base_life(player_party[i]))]; 
                
                // Select the i-th  enemy party member if alive, otherwise select enemy leader
                Character* enemy_party_member_ptr  = enemy_party[i*(i && get_base_life(enemy_party[i]))];
                verbose = !(get_base_life(player_party[i]) && get_base_life(enemy_party[i]));
                
                // if not both leaders, start a fight round
                if(player_party_member_ptr!=player_ptr || enemy_party_member_ptr!=enemy_ptr)
                {
                    fight_round(player_party_member_ptr, enemy_party_member_ptr, verbose);
                }
            }
            printf("----------------------------------\n");


            if(player_party_size>min_size) // You have more party members
            {
                for(i=min_size;i<player_party_size;++i)
                {
                    many_vs_one_fight(player_party[i], player_party_size-enemy_party_size, enemy_ptr);
                }
            }
            else // The enemy party has more members
            {
                for(i=min_size;i<enemy_party_size;++i)
                {
                    many_vs_one_fight(enemy_party[i], enemy_party_size - player_party_size, player_ptr);
                }
            }
        }
    }
    
    // TODO: Recompute vectors and sizes
}


// --------------------------------------------------------------------------------------------------------
// Initialization functions

void initNames(void)
{
    uint8_t i;
    
    for(i=0;i<NUM_OF_CHARACTERS;++i)
    {
        memcpy(&characters[i].name,characters_names[i],MAX_NAME_SIZE);
    }
}


void initFeatures(uint8_t character_index)
{
    uint8_t stat_index;
    
    // printf("\nDEBUG %d\n", character_index);
    for(stat_index=0;stat_index<NUM_OF_STATS;++stat_index)
    {
        set_base_stat(&characters[character_index], stat_index, characters_stats[character_index][stat_index]);
    }
}


void initCharacters(void)
{
    uint8_t char_index;
    
    initNames();
    
    for(char_index=0;char_index<NUM_OF_CHARACTERS;++char_index)
    {
        initFeatures(char_index);
    }
}



// "race",   "class",    "life",  "strength",  "dexterity",  "charisma",  "experience",  "stamina",   "mana",  "gold"};
void set_base_stats(Character *character_ptr, const char* name,
               uint8_t race, uint8_t class, 
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
    
    initFeatures(ULRIK);
    
    set_leader(player_party[LEADER], NULL);

    
    player_party_size = 3;

    for(i=1;i<player_party_size;++i)
    {
        set_leader(&humans[i-1], player_party[LEADER]);
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
    
    ulrik_ptr->stat[LIFE] = ULRIK_LIFE;
    
    set_leader(enemy_party[LEADER], NULL);
    
    enemy_party_size = 1+rand()%7;

    // Initialize enemy minions
    for(i=1;i<enemy_party_size;++i)
    {
        set_leader(&orcs[i-1], enemy_party[LEADER]);
        soldier_name[14] = '0'+i; //soldier_name
        set_base_stats(&orcs[i-1],soldier_name, ORC_SOLDIER_STATS);
        enemy_party[i] = &orcs[i-1];
    }

}


// ----------------------------------------------


void print_conan(void)
{
    printf("   _____  \n");
    printf("  / ____| \n");
    printf(" | |      \n");
    printf(" | |     ___  _ __   __ _ _ __  \n");
    printf(" | |    / _ \\| '_ \\ / _` | '_ \\ \n");
    printf(" | |___| (_) | | | | (_| | | | |\n");
    printf("  \\_____\\___/|_| |_|\\__,_|_| |_|\n");
    printf("\n");
}


void print_market(void)
{
    printf("  __  __            _        _   \n");
    printf(" |  \\/  |          | |      | |  \n");
    printf(" | \\  / | __ _ _ __| | _____| |_ \n");
    printf(" | |\\/| |/ _` | '__| |/ / _ \\ __|\n");
    printf(" | |  | | (_| | |  |   <  __/ |_ \n");
    printf(" |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|\n");
    printf("\n");
}


void print_the_inn(void)
{
    printf("  _______ _            _____             \n");
    printf(" |__   __| |          |_   _|            \n");
    printf("    | |  | |__   ___    | |  _ __  _ __  \n");
    printf("    | |  | '_ \\ / _ \\   | | | '_ \\| '_ \\ \n");
    printf("    | |  | | | |  __/  _| |_| | | | | | |\n");
    printf("    |_|  |_| |_|\\___| |_____|_| |_|_| |_|\n");
    printf("\n");
}


void print_the_square(void)
{
    printf("  _______ _             _____                            \n");
    printf(" |__   __| |           / ____|                           \n");
    printf("    | |  | |__   ___  | (___   __ _ _   _  __ _ _ __ ___ \n");
    printf("    | |  | '_ \\ / _ \\  \\___ \\ / _` | | | |/ _` | '__/ _ \n");
    printf("    | |  | | | |  __/  ____) | (_| | |_| | (_| | | |  __/\n");
    printf("    |_|  |_| |_|\\___| |_____/ \\__, |\\__,_|\\__,_|_|  \\___|\n");
    printf("                                 | |                     \n");
    printf("                                 |_|                     \n");
    printf("\n");
}


void print_journey(void)
{
    printf("       _                                   \n");
    printf("      | |                                  \n");
    printf("      | | ___  _   _ _ __ _ __   ___ _   _ \n");
    printf("  _   | |/ _ \\| | | | '__| '_ \\ / _ \\ | | |\n");
    printf(" | |__| | (_) | |_| | |  | | | |  __/ |_| |\n");
    printf("  \\____/ \\___/ \\__,_|_|  |_| |_|\\___|\\__, |\n");
    printf("                                      __/ |\n");
    printf("                                     |___/ \n");
    printf("\n");
}


// --------------------------------------------------------------------------------------------------------

void square(void)
{
    square_start:
    
    clrscr();
    print_the_square();
    
    printf("\n\n");
    printf("You are in the main square of the village where you can meet heroes and mercenaries\n");
    printf("\n");
    printf("(m) Start your trip to the Market\n");
    printf("\n");
    printf("(i) Enter the Inn\n");
    printf("\n");
    
    selection = getchar();
    
    switch(selection)
    {
        case 'm':
            destination = MARKET;
            destination_distance = 5;
            quest_week = 1;
            player_location = WAY_THERE;
            break;
        case 'i': 
            player_location = INN;
            break;
        default: 
            goto square_start;
    }
}


void inn(void)
{
    inn_start:
    clrscr();
    print_the_inn();
    
    printf("\n\n");
    printf("You are at the Inn, where new adventures are proposed\n");
    printf("\n");
    printf("(1) A short quest\n");
    printf("\n");
    printf("(2) A longer quest\n");
    printf("\n");
    printf("(3) Ultimate quest to fight against Lucifer\n");
    printf("\n");
    printf("(s) Leave the Inn and go back to the main square\n");
    printf("\n");
    
    selection = getchar();
    
    switch(selection)
    {
        case '1':
            destination = EASY_QUEST;
            destination_distance = EASY_QUEST_DISTANCE;
            quest_week = 1;
            player_location = WAY_THERE;
            break;
        case '2':
            destination = HARD_QUEST;
            destination_distance = HARD_QUEST_DISTANCE;
            quest_week = 1;
            player_location = WAY_THERE;
            break;
        case '3':
            destination = FINAL_QUEST;
            destination_distance = FINAL_QUEST_DISTANCE;
            quest_week = 1;
            player_location = WAY_THERE;
            break;
        case 's': 
            player_location = SQUARE;
            break;
        default: 
            goto inn_start;
    }
}


void normalize_player(void)
{
    uint8_t count = 0;
    uint8_t i;
    
    for(i=0;i<player_party_size;++i)
    {
        if(get_base_life(player_party[i]))
        {
            ++count;
            aux_player_party[count]= *player_party[i];
        }
    }
    
    printf("\n--- DEBUG normalize_player\n");
    printf("DEBUG ---- count %d\n", count);
    
    for(i=1;i<count;++i)
    {
        *player_party[i] = aux_player_party[i]; // TODO: change to multiple single field copies for 8-bit targets
    }
    player_party_size = count;
}


void journey(void)
{
    initEnemyParty();
    
    journey_start:
    
    clrscr();
    print_journey();
    
    printf("\n\n");
    printf("You are on the week number %u of your journey\n", quest_week);
    if(player_location==WAY_BACK)
    {
        printf("You are on your way back to the village"); 
    }
    printf("\n");
        
    printf("Your party is made of %d soldiers\n", player_party_size);
    
    printf("\n");
    
    printf("You encounter a group of %d evil enemies\n", enemy_party_size);
    printf("\n");
    
    printf("(f) Fight the enemies");
    
    printf("\n");
    
    selection = getchar();
    switch(selection)
    {
        case 'f': 
            party_fight();
            normalize_player(); // TODO: to be correctly implemented
            // showParty(player_party, player_party_size, showFightStats);
            
            printf("\n---DEBUG after party_fight, normalize, showParty\n");
            
            break;
        default: 
            goto journey_start;
    }

    if(++quest_week==destination_distance)
    {
        player_location = destination;
        quest_week = 1;
    }    
}


void easy_quest(void)
{
    printf("You have reached the destination\n");
    
    getchar();
    
    player_location = WAY_BACK;
    destination_distance = EASY_QUEST_DISTANCE;
    destination = SQUARE;
    
    
}

void hard_quest(void)
{
    printf("You have reached the destination\n");
    
    getchar();
    
    player_location = WAY_BACK;
    destination_distance = HARD_QUEST_DISTANCE;
    destination = SQUARE;
    
    
}

void final_quest(void)
{
    printf("You have reached the final destination\n");
    
    getchar();
}


void market(void)
{
    market_start:
    
    clrscr();
    print_market();
    
    printf("\n");
    
    printf("You are at the market\n");
    
    selection = getchar();
    switch(selection)
    {
        case 'b': // Go back
            player_location = WAY_BACK;
            quest_week = 1;
            destination_distance = MARKET_DISTANCE;
            destination = SQUARE;
            break;
        default: 
            goto market_start;
    }
}


int main(void)
{
    uint8_t final_quest_done = 0;
    
    clrscr();
    print_conan();
    
    printf("Press a key to start\n");
    getchar();
    
    initCharacters();
    
    initPlayerParty();
    initEnemyParty();
   
    player_ptr = player_party[LEADER];
    enemy_ptr = enemy_party[LEADER];

    player_location = SQUARE;

    while(!final_quest_done)
    {
        switch(player_location)
        {
            case SQUARE:
                square();
                break;
            case INN:
                inn();
                break;
            case WAY_THERE:
                journey();
                break;
            case WAY_BACK:
                journey();
                break;
            case EASY_QUEST:
                easy_quest();
                break;
            case HARD_QUEST:
                hard_quest();
                break;
            case FINAL_QUEST:
                final_quest();
                break;
            case MARKET:
                market();
                break;
        }
        
        getchar();
    }
    

    
    return 0;
}


