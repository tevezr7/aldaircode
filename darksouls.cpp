#include <iostream>

using namespace std;

#include <iomanip>

#include <cstdlib>

#include <time.h>

int main()
{
    srand(time(0));
    string enemies[3] = {"Lothric Knight","Artorias of the Abyss","blank"};
    int bosshp[3] = {1500,2500,10000};
    int bossend[3] ={150,250,10000};
    string herostats[6] ={"Vitality","Strength","Intelligence","Endurance","Luck","Defense",};
    int herovalues[6] = {10,10,10,10,10,10};
    int bosslimit = 3;
    int upgradelevel = 1;
    int herohp = 100*herovalues[0];
    int herohptemp = 100*herovalues[0];
    int herostam = 10*herovalues[3];
    int herostamtemp = 10*herovalues[3];
    int heroman = 10*herovalues[2];
    int heromantemp = 10*herovalues[2];
    int magdam = 0;
    int knightdam = 0;
    int heavymagattack;
    int healcount;
    string heroname;
    string heroclass;
    cout<<"Welcome to Dark Souls!\n";
    cout<<"Choose your name: ";
    cin>>heroname;
    cout<<"\nWelcome, "<<heroname;cout<<".\n";
    classselection:
    cout<<"Choose your class\n";
    cout<<"1.| Knight | 2.| Mage | 3.| Knight Description | 4.| Mage Description | 5. | Combat Tutorial |\n";
    cin>>heroclass;
    if(heroclass == "1")
    {
        herovalues[0] = 15;
        herovalues[1] = 16;
        herovalues[2] = 5;
        herovalues[3] = 11;
        herovalues[4] = 15;
        herovalues[5] = 30;
        herohp = 100*herovalues[0];
        herohptemp = 100*herovalues[0];
        herostam = 10*herovalues[3];
        herostamtemp = 10*herovalues[3];
        heroman = 10*herovalues[2];
        heromantemp = 10*herovalues[2];
        cout<<"You are now a Knight!\n";
        cout<<"You will now begin your journey, good luck!\n";
        goto postclassselect;
     
    }
    if(heroclass == "2")
    {
        herovalues[0] = 13;
        herovalues[1] = 7;
        herovalues[2] = 15;
        herovalues[3] = 16;
        herovalues[4] = 11;
        herovalues[5] = 20;
        herohp = 100*herovalues[0];
        herohptemp = 100*herovalues[0];
        herostam = 10*herovalues[3];
        herostamtemp = 10*herovalues[3];
        heroman = 10*herovalues[2];
        heromantemp = 10*herovalues[2];
        cout<<"You are now a Mage!\n";
        cout<<"You will now begin your journey, good luck!\n";
        goto postclassselect;
    }
    if(heroclass == "3")
    {
        cout<<"\nKnights are strong and noble warriors who favor melee combat."; 
        cout<<"The starting stats for Knights are:\n| Vitality: 15| Strength: 16 | Intelligence: 5 | Endurance: 11 | Luck: 15 |";
        cout<<"\nKnights begin with Heavy Armor along with a Longsword and Shield\n\n";
        goto classselection;
    }
    if(heroclass == "4")
    {
        cout<<"\nMages are intelligent and quick combatants who favor magic combat.";
        cout<<"The starting stats for Mages are:\n| Vitality: 13| Strength: 7 | Intelligence: 15 | Endurance: 13 | Luck: 11 |";
        cout<<"\nMages begin with Light Armor along with a Staff and Parrying Dagger\n\n";
        goto classselection;
    }
    if(heroclass == "5")
    {
        cout<<"In this game, you must manage your stamina. If your opponent has zero stamina, your enemy’s posture will break. The same also applies to the player! During a posture break, there is an opportunity for a critical strike that does tons of damage.\n";
        goto classselection;
    }
    postclassselect:
    string input;
    int checkreq = 0;
    cout<<"You awaken from a grave, you died many years ago but you have been suddenly revived by an ember. You make your way out of the cemetery and come across a split in paths. Do you go off of the beaten path into the crooked alley or continue to march along?\n";
    cout<<"Choose Path or Alley: ";
    cin>>input;
    if(input == "Alley"||input == "alley")
    {
        cout<<"You go down the alley and find a chest! You open it up and find an upgrade for your weapon that increases its damage by 5!\n";
        cout<<"However, the alley was a dead end so you return back to the path you were following.\n";
        int upgradelevel = 5;
        if(heroclass == "1")
        {
            knightdam = herovalues[1] + 30 + upgradelevel;
            checkreq = 1;
            cout<<"\nNew Weapon Damage = "<<knightdam<<endl;
            goto pew;
        }
        if(heroclass == "2")
        {
            magdam = herovalues[2] + 30 + upgradelevel;
            checkreq = 1;
            cout<<"\nNew Weapon Damage = "<<magdam<<endl;
            goto pew;
        }
    }
    else
    upgradelevel = 1;
    if(heroclass == "1" && checkreq == 0)
    {
        knightdam = herovalues[1] + 30 + upgradelevel;
        cout<<"\nNew Weapon Damage = "<<knightdam<<endl;
        goto pew;
    }
    if(heroclass == "2" && checkreq == 0)
    {
        magdam = herovalues[2] + 30 + upgradelevel;
        cout<<"\nNew Weapon Damage = "<<magdam<<endl;
        goto pew;
    }
    pew:
    cout<<"While continuing along your path, you spot your first enemy!\n A lothric knight appears along your path!\n";
    int attack;
    if(magdam > 0 )
    {
        attack = magdam * 2;
        goto fightstart;
    }
    if(knightdam > 0 )
    {
        attack = knightdam * 2;
        goto fightstart;
    }
    fightstart:
    healcount = 5;
    while(bosshp[0]>0)
    {
        beginlothric:
        if(herohptemp<0)
        {
            cout<<"\nY O U  D I E D\n";
            return 0;
        }
        else
        cout<<endl<<heroname<<" || HP: "<<herohptemp<<" | STM: "<<herostamtemp<<" | MAN: "<<heromantemp<<" | \n";
        cout<<endl<<enemies[0]<<" || HP: "<<bosshp[0]<<" | STM: "<<bossend[0]<<" | \n";
        if(herostamtemp <= 0)
        {
            cout<<"You collapse to the ground as your poise has been broken!\n";
            cout<<"Lothric Knight strikes you critically for 200 HP!\n";
            herohptemp = herohptemp - 200;
            herostamtemp = herostamtemp + 30;
            bossend[0] = bossend[0] - 20;
            goto beginlothric;
        }
        if(bossend[0] <= 0)
        {
            poisebreak:
            cout<<"Lothric Knight's poise has been broken!\n";
            cout<<"Press X for an Immense Strike!\n";
            cout<<"Press X: ";
            string critical;
            cin>>critical;
            if(critical == "x"||critical == "X")
            {
                cout<<"You pierce the Knight's armor with your blade and strike him for 200 HP!\n";
                bosshp[0] = bosshp[0] - 200;
                bossend[0] = bossend[0] + 60;
                if(bosshp[0]<=0)
                {
                    goto fightend;
                }
                else
                {
                    goto beginlothric;
                }
                
            }
            else
            {
                cout<<"\nYou missed your opportunity!\n";
                bossend[0] = bossend[0] + 30;
                goto beginlothric;
            }
            
        }
        int lothattack = 120;
        cout<<"\nChoose your move!\n";
        cout<<"\n| 1. Attack [15 STM] | 2. Dodge [10 STM] | 3. Parry [.25 Chance] | 4. Heavy Attack [25 STM/30 MAN] | 5. Rest [30+ STM] | 6. Heal [75+ HP] "<<healcount<<" Uses Left |";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
               if(heroclass == "2")
               {
                   herostamtemp = herostamtemp - 15;
                   cout<<"You launch a fireball from your staff at the Knight!\n";
                   cout<<"It hits for "<<attack<<"HP!\n";
                   bosshp[0] = bosshp[0] - attack;
                   if(bosshp[0]<=0)
                   {
                       goto fightend;
                   }
                   cout<<"The Lothric Knight jumps at you with his Sword!\n";
                   cout<<"It hits for "<<lothattack<<"HP!\n";
                   herohptemp = herohptemp - lothattack;
                   bossend[0] = bossend[0] - 20;
                   break;
               }
               else
               {
                   herostamtemp = herostamtemp - 15;
                   cout<<"You swing your sword at the Knight!\n";
                   cout<<"It hits for "<<attack<<"HP!\n";
                   bosshp[0] = bosshp[0] - attack;
                   if(bosshp[0]<=0)
                   {
                       goto fightend;
                   }
                   cout<<"The Lothric Knight charges at you with a blinding slash!\n";
                   cout<<"It hits for "<<lothattack<<"HP!\n";
                   herohptemp = herohptemp - lothattack;
                   break;
               }
            }
            case 2:
            {
                herostamtemp = herostamtemp - 10;
                cout<<"You dodge the knight's slash!\n";
                bossend[0] = bossend[0] - 30;
                break;
            }
            case 3: 
            {
                int parrychance = rand( ) % 100 + 1;
                parrychance = parrychance - herovalues[4];
                if(parrychance <= 25)
                {
                    cout<<"You parried the knight!\n";
                    goto poisebreak;
                    break;
                }
                else
                cout<<"You missed your parry! The Lothric Knight strikes you for "<<lothattack<<" HP!\n";
                herohptemp = herohptemp - lothattack;
                break;

            }
            case 4:
            {
                if(heroclass == "2")
                {
                    if(heromantemp <=0)
                    {
                        cout<<"\nYour spell fails due to your lack of mana!\n";
                        cout<<"The knight strikes you critically in your failure for 150 HP!\n";
                        herohptemp = herohptemp - 150;
                        break;
                    }
                    else
                    heavymagattack = attack * 1.75;
                    cout<<"You begin to charge a volcanic fireball to launch at the knight! It has charged, you throw it and strike the knight for "<<heavymagattack<<" HP!\n";
                    cout<<"The knight is struck for "<<heavymagattack<<" HP!\n";
                    bosshp[0] = bosshp[0] - heavymagattack;
                    heromantemp = heromantemp - 30;
                    if(bosshp[0]<=0)
                    {
                       goto fightend;
                    }
                    break;
                }
                else
                {
                    int heavyknightattack = attack * 1.35;
                    cout<<"You prepare to strike the knight with all your might! You slash him with all your might and hit him heavily!\n";
                    cout<<"The knight is struck for "<<heavyknightattack<<" HP!\n";
                    bosshp[0] = bosshp[0] - heavyknightattack;
                    herostamtemp = herostamtemp - 25;
                    if(bosshp[0]<=0)
                    {
                       goto fightend;
                    }
                    cout<<"The Lothric Knight retaliates with a slash of his own!\n";
                    cout<<"He strikes you for "<<lothattack<<" HP!";
                    herohptemp = herohptemp - lothattack;
                    bossend[0] = bossend[0] - 30;
                    break;
                }
            }
            case 5:
            {
                cout<<"You rest and do not make a move in order to recover your stamina!\n";
                herostamtemp = herostamtemp + 30;
                bossend[0] = bossend[0] + 15;
                break;
            }
            case 6:
            {
                if(healcount<=0)
                {
                    cout<<"You don't have any Estus!\n";
                    goto beginlothric;
                    break;
                }
                cout<<"You take a sip of your Estus Flask in order to boost your health!\n";
                herohptemp = herohptemp + 75;
                bossend[0] = bossend[0] + 20;
                healcount--;
                break;
            }
            default:
            {
                cout<<"That's not an option!\n";
                goto beginlothric;
                break;
            }
        }
    }
    fightend:
    cout<<"After dealing "<<enemies[0]<<" a fatal blow, he drops to the ground and you calmly rejoice in your great victory.\n";
    cout<<"Upon defeating the Knight, you find that his body turns into a bonfire that recovers all your attributes!\n He drops you a special piece of gear that increases your health by 500 points!\n";
    cout<<"On top of this, you have gotten the option to level up 10 times!\n";
    int z=10;
    while(z>0)
    {
        cout<<"You have "<<z<<" level-ups left!\n";
        cout<<"Which stat do you want to upgrade?\n";
        cout<<"Choose Stat: ";
        for(int i = -1; i<=4; i++)
        {
            if(i>=0)
            {
                cout<<"| "<<i<<". "<<herostats[i]<<" : "<<herovalues[i]<<" | ";
            }
        }
        int inputnum;
        cin>>inputnum;
        switch(inputnum)
        {
            case 0:
            {
                cout<<"You have leveled up your "<<herostats[inputnum]<<" by one!\n";
                herovalues[inputnum] = herovalues[inputnum] + 1;
                cout<<"New value of "<<herostats[inputnum]<<" is "<<herovalues[inputnum]<<endl;
                z--;
                break;
            }
            case 1:
            {
                cout<<"You have leveled up your "<<herostats[inputnum]<<" by one!\n";
                herovalues[inputnum] = herovalues[inputnum] + 1;
                cout<<"New value of "<<herostats[inputnum]<<" is "<<herovalues[inputnum-1]<<endl;
                z--;
                break;
            }
            case 2:
            {
                cout<<"You have leveled up your "<<herostats[inputnum]<<" by one!\n";
                herovalues[inputnum] = herovalues[inputnum] + 1;
                cout<<"New value of "<<herostats[inputnum]<<" is "<<herovalues[inputnum-1]<<endl;
                z--;
                break;
            }
            case 3:
            {
                cout<<"You have leveled up your "<<herostats[inputnum]<<" by one!\n";
                herovalues[inputnum] = herovalues[inputnum] + 1;
                cout<<"New value of "<<herostats[inputnum]<<" is "<<herovalues[inputnum-1]<<endl;
                z--;
                break;
            }
            case 4:
            {
                cout<<"You have leveled up your "<<herostats[inputnum]<<" by one!\n";
                herovalues[inputnum] = herovalues[inputnum] + 1;
                cout<<"New value of "<<herostats[inputnum]<<" is "<<herovalues[inputnum-1]<<endl;
                z--;
                break;
            }
        }
    }
    cout<<"You have finished leveling up! You are now level 11!\n";
    cout<<"These are your stats!\n";
    for(int r = -1; r<=3; r++)
    {
        if(r>=0)
        {
            cout<<"| "<<r<<". "<<herostats[r]<<" : "<<herovalues[r]<<" | ";
        }
    }
    herohp = 100*herovalues[0];
    herostam = 10*herovalues[3];
    heroman = 10*herovalues[2];
    herohp = herohp + 500;
    herohptemp = herohp;
    herostamtemp = herostam;
    heromantemp = heroman;
    healcount = 5;
    if(knightdam>magdam)
    {
        knightdam = herovalues[1] + 30 + upgradelevel;
        attack = knightdam*2;
    }
    if(magdam>knightdam)
    {
        magdam = herovalues[2] + 30 + upgradelevel;
        attack = magdam*2;
    }
    cout<<"\nDo you want to see your other stats?\n";
    cin>>input;
    if(input == "yes"||input == "Yes")
    {
        cout<<"Health: "<<herohptemp<<"/"<<herohp<<" Stamina: "<<herostamtemp<<"/"<<herostam<<" Mana: "<<heromantemp<<"/"<<heroman<<" Damage: "<<attack<<" Defense: "<<herovalues[5]<<endl;
    }
    else
    cout<<"\nYou wrap up your time at the bonfire and refill your estus flask!\n";
    cout<<"You continue to walk down the path you started following from when you awoke in the graveyard. You reach the side of a cliff and find a large castle looming in the distance. This castle can only be the Lothric Castle of legend. It is said that the god who saved humanity from the dragons resides there in a weakened form.\n";
    cout<<"You arrive at the gates but you are confronted by the most esteemed soldier in the Lothric Army! The one and only Artorias of the Abyss appears before you!\n";
    cout<<"''Prepare to die, fool!'' he screams. You ready your weapon and begin fighting the greatest knight to grace mankind!\n";
    while(bosshp[1]>0)
    {
        beginartorias:
        if(herohptemp<0)
        {
            cout<<"\nY O U  D I E D\n";
            return 0;
        }
        else
        cout<<endl<<heroname<<" || HP: "<<herohptemp<<" | STM: "<<herostamtemp<<" | MAN: "<<heromantemp<<" | \n";
        cout<<endl<<enemies[1]<<" || HP: "<<bosshp[1]<<" | STM: "<<bossend[1]<<" | \n";
        if(herostamtemp <= 0)
        {
            cout<<"You collapse to the ground as your poise has been broken!\n";
            cout<<"Artorias gathers dark energy from the Abyss and impales you!\n";
            cout<<"He strikes you for 500 HP!\n";
            herohptemp = herohptemp - 500;
            herostamtemp = herostamtemp + 40;
            bossend[1] = bossend[1] - 20;
            goto beginartorias;
        }
        if(bossend[1] <= 0)
        {
            artoriasbreak:
            cout<<"Artorias' poise has been broken!\n";
            cout<<"Press X for an Immense Strike!\n";
            cout<<"Press X: ";
            string critical;
            cin>>critical;
            if(critical == "x"||critical == "X")
            {
                cout<<"You pierce Artorias' fierce armor with your blade and strike him for 350 HP!\n";
                bosshp[1] = bosshp[1] - 350;
                bossend[1] = bossend[1] + 60;
                if(bosshp[1]<=0)
                {
                    goto fightbyebye;
                }
                else
                {
                    goto beginartorias;
                }
                
            }
            else
            {
                cout<<"\nYou missed your opportunity!\n";
                bossend[1] = bossend[1] + 30;
                goto beginartorias;
            }
            
        }
        int artoriasattack = 80;
        cout<<"\nChoose your move!\n";
        cout<<"\n| 1. Attack [15 STM] | 2. Dodge [10 STM] | 3. Parry [.25 Chance] | 4. Heavy Attack [25 STM/30 MAN] | 5. Rest [30+ STM] | 6. Heal [75+ HP] "<<healcount<<" Uses Left |";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
               if(heroclass == "2")
               {
                   herostamtemp = herostamtemp - 15;
                   cout<<"You launch a fireball from your staff at the Knight!\n";
                   cout<<"It hits for "<<attack<<"HP!\n";
                   bosshp[1] = bosshp[1] - attack;
                   if(bosshp[1]<=0)
                   {
                       goto fightbyebye;
                   }
                   cout<<"Artorias sends a beam at you with his Sword!\n";
                   cout<<"It hits for "<<artoriasattack<<"HP!\n";
                   herohptemp = herohptemp - artoriasattack;
                   bossend[1] = bossend[1] - 20;
                   break;
               }
               else
               {
                   herostamtemp = herostamtemp - 15;
                   cout<<"You swing your sword at the Knight!\n";
                   cout<<"It hits for "<<attack<<"HP!\n";
                   bosshp[1] = bosshp[1] - attack;
                   if(bosshp[1]<=0)
                   {
                       goto fightbyebye;
                   }
                   cout<<"Artorias charges at you with a dark slash!\n";
                   cout<<"It hits for "<<artoriasattack<<"HP!\n";
                   herohptemp = herohptemp - artoriasattack;
                   break;
               }
            }
            case 2:
            {
                herostamtemp = herostamtemp - 10;
                cout<<"You dodge the knight's slash!\n";
                bossend[1] = bossend[1] - 30;
                break;
            }
            case 3: 
            {
                int parrychance = rand( ) % 100 + 1;
                parrychance = parrychance - herovalues[4];
                if(parrychance <= 25)
                {
                    cout<<"You parried Artorias in the midst of his sweeping attack!\n";
                    goto artoriasbreak;
                    break;
                }
                else
                cout<<"You missed your parry! Artorias strikes you for "<<artoriasattack<<" HP!\n";
                herohptemp = herohptemp - artoriasattack;
                break;

            }
            case 4:
            {
                if(heroclass == "2")
                {
                    if(heromantemp <=0)
                    {
                        cout<<"\nYour spell fails due to your lack of mana!\n";
                        cout<<"Artorias strikes you critically in your failure for 250 HP!\n";
                        herohptemp = herohptemp - 250;
                        break;
                    }
                    else
                    int heavymagattack = attack * 1.75;
                    cout<<"You begin to charge a volcanic fireball to launch at the knight! It has charged, you throw it and strike Artorias for "<<heavymagattack<<" HP!\n";
                    cout<<"Artorias is struck for "<<heavymagattack<<" HP!\n";
                    bosshp[1] = bosshp[1] - heavymagattack;
                    heromantemp = heromantemp - 40;
                    if(bosshp[1]<=0)
                    {
                       goto fightbyebye;
                    }
                    break;
                }
                else
                {
                    int heavyknightattack = attack * 1.35;
                    cout<<"You prepare to strike the knight with all your might! You slash him with all your might and hit him heavily!\n";
                    cout<<"The knight is struck for "<<heavyknightattack<<" HP!\n";
                    bosshp[1] = bosshp[1] - heavyknightattack;
                    herostamtemp = herostamtemp - 25;
                    if(bosshp[1]<=0)
                    {
                       goto fightbyebye;
                    }
                    cout<<"Artorias retaliates with a slash of his own!\n";
                    cout<<"He strikes you for "<<artoriasattack<<" HP!";
                    herohptemp = herohptemp - artoriasattack;
                    bossend[0] = bossend[0] - 30;
                    break;
                }
            }
            case 5:
            {
                cout<<"You rest and do not make a move in order to recover your stamina!\n";
                herostamtemp = herostamtemp + 30;
                bossend[1] = bossend[1] + 15;
                break;
            }
            case 6:
            {
                if(healcount<=0)
                {
                    cout<<"You don't have any Estus!\n";
                    goto beginartorias;
                    break;
                }
                cout<<"You take a sip of your Estus Flask in order to boost your health!\n";
                herohptemp = herohptemp + 75;
                bossend[1] = bossend[1] + 20;
                healcount--;
                break;
            }
            default:
            {
                cout<<"That's not an option!\n";
                goto beginartorias;
                break;
            }
        }
    }
    fightbyebye:
    cout<<"Artorias of the Abyss collapses to the ground and dies with his sword in his hand. He fades away into mist and the area his body once lay in turns into a bonfire. You decide to rest and know that when you get up, you will have a long journey inside of Lothric Castle ahead of you.\n";
    cout<<"\nY O U  W I N";
    return 0;
}    
