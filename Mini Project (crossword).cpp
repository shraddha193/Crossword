/* ASSIGNMENT   : GROUP C - CROSSWORD GAME
 *
 * TEAM MEMBERS:
 * 1. Madhura Kurhadkar (2431)
 * 2. Samruddhi Lahoti  (2432)
 * 3. Gauri Lokhande    (2433)
 * 4. Malvika Menon     (2436)
 *
 * YEAR: SY BTech
 * BRANCH:    Computer Science
 * DIVISION: B
 */

#include<iostream>
#include<string.h>
using namespace std;

class node
{
    friend class crossword;
    string ans;
    int op;
    node *link;
public:
    node()
    {
        ans = '\0';
        op = 0;
        link = NULL;
    }
    node(string a, int opt)
    {
        ans = a;
        op = opt;
        link = NULL;
    }
};

class crossword                                        // operation on one crossword puzzle
{
    string a;
    int cnt;
    node *head;
public:
    // default constructor of class crossword
    crossword()
    {
        a = '\0';
        cnt = 0;
        head = NULL;
    }

    void assign(int no_clues)                                        // assignment function for pictorial representation of the crossword
    {
        node *temp, *ptr;
        for(int i=0;i<no_clues;i++)
        {
            for(int j=0;j<7;j++)
            {
                a[j] = '   ';
            }
            temp = new node(a,i+1);
            if(head==NULL)
            {
                head = temp;
                ptr = head;
            }
            else
            {
                ptr->link = temp;
                ptr = ptr->link;
            }
        }
    }

    void check(string s, int opt)                        // method to accept the answer and to check the given answer.
    {
        node  *ptr;
        cout << "Enter your answer (IN CAPITALS ONLY)" << endl;
        cin >> a;
        if(a==s)                                                // checking if answer is correct
        {
            cout << endl << "!! Correct answer !!" << endl;
            ptr = head;
            while((ptr->op != opt) && ptr!=NULL)                // matching the option number with a node
            {
                ptr = ptr->link;
            }
            if(ptr!=NULL)                                        // storing the answer for a valid option number
            {
                ptr->ans = a;
                cnt++;							// counting the number of options answered correctly
                cout << endl << "     ___ ___ ___ ___ ___ ___ ___ " << endl;
                display();
            }
            else
                cout << "\n** Invalid option number **" << endl;
            }
        else
            cout << "\n!! Incorrect answer !!" << endl;
    }
    // displaying the crossword
    void display()
    {
        node *ptr;
        int l, i=0;
        ptr = head;
        while(ptr->link!=NULL)
        {

            cout << ptr->op << ".  | ";
            l = ptr->ans.length();
            for(i=0;i<l;i++)
            {
                cout << ptr->ans[i] << " | ";
            }
            while(i<7)
            {
                cout << "  | ";
                i++;
            }
            cout << endl << "    |___|___|___|___|___|___|___|" << endl;
            ptr = ptr->link;
        }
        cout << ptr->op << ". | ";
        l = ptr->ans.length();
        for(i=0;i<l;i++)
        {
            cout << ptr->ans[i] << " | ";
        }
        while(i<7)
        {
            cout << "  | ";
            i++;
        }
        cout << endl << "    |___|___|___|___|___|___|___|" << endl;
        if(cnt==10)			// declaring a win if all clues have been solved
        	cout << "\n!!!! YOU HAVE COMPLETED THE CROSSWORD. CONGRATULATIONS !!!!\n";
    }
};

class multiple                                            // setup for multiple crosswords
{
    crossword c[5];
    string s;
    int opt;
public:
    multiple()                                            // default constructor
    {
        s = '\0';
        opt = 0;
    }
    void clues()                                        // displaying clues for multiple crosswords
    {
        for(int i=0;i<5;i++)
            c[i].assign(10);                                // creating 5 blank crosswords
        int ch, ch1, ch2;
        do
        {
            cout << "\tWhich crossword do you wish to solve?\n" << endl;            // accept  choice from user regarding which crossword to solve
            cout << "\t1. Crossword 1.\n\t2. Crossword 2.\n\t3. Crossword 3.\n\t4. Crossword 4.\n\t5. Crossword 5.\n\t6. Exit" << endl;
            cin >> ch;
            cout << endl << "\t\t****** CLUES *******" << endl << endl;
            if(ch!=6)
            {
                cout << "\tCurrent status of the puzzle:\n" << endl << "     ___ ___ ___ ___ ___ ___ ___ " << endl;
                c[ch-1].display();
                do
                {
                    switch(ch)                            // displaying clues for the crossword that is chosen
                    {
                        case 1:
                            cout << endl << "\t1.  More than bad (SWORE)\n\t2.  Sound made by a sheep (TABLE)\n\t3.  Movement of water (WOLF)\n\t4.  A long dress (BORE)" << endl;
                            cout << "\t5.  To jump (PALE)\n\t6.  A story (LATE)\n\t7.  Average (NAME)\n\t8.  A sickness (SEASIDE)\n\t9.  One time (CONE)\n\t10. Vessel (NAP)"<< endl << endl;
                            break;
                        case 2:
                            cout << endl << "\t1.  Far away (METEOR)\n\t2.  A thing on a list (TIME)\n\t3.  A limb (RAM)\n\t4.  An animal we ride (SHORE)" << endl;
                            cout << "\t5.  Something that makes you sneeze (GALLERY)\n\t6.  A juicy fruit (LEMON)\n\t7.  An insect that stings (PAWS)\n\t8.  Something you bake (BEARD)\n\t9.  We ____ a book (DEAR)\n\t10. Something you serve on (LEAPT)"<< endl << endl;
                            break;
                        case 3:
                            cout << endl << "\t1.  A person who makes bread (BREAK)\n\t2.  Hair around a lion's neck' (NAME)\n\t3.  A place to see stars and planets (CAPES)\n\t4.  A thing that babies wear (PRAISED)" << endl;
                            cout << "\t5.  Less narrow (WEIRD)\n\t6.  Something to be careful of (GARDEN)\n\t7.  An angry stare (LARGE)\n\t8.  Not awake (PLEASE)\n\t9.  A marine mammal (SALE)\n\t10. A dragon's home (LIAR)"<< endl << endl;
                            break;
                        case 4:
                            cout << endl << "\t1.  Where land meets sea (COATS)\n\t2.  A part of your arm (BELOW)\n\t3.  Try to hear (SILENT)\n\t4.  Past tense of spell (SLEPT)" << endl;
                            cout << "\t5.  Fix a written work (DIET)\n\t6.  Another word for snake (PRESENT)\n\t7.  A piece of beef (SKATE)\n\t8.  A period of time (EAR)\n\t9.  Not as hard (FOREST)\n\t10. Characteristics of something (ARTIST)"<< endl << endl;
                            break;
                        case 5:
                            cout << endl << "\t1. Be a thief (STALE)\n\t2. Make bigger (GENERAL)\n\t3. A spot on your shirt (SAINT)\n\t4. An organ that pumps blood (EARTH)";
                            cout << "\n\t5. A square or a triangle (PHASE)\n\t6. Another word for warn (ALTER)\n\t7. Pieces of furniture to serve food on (STABLE)\n\t8. A seasoning (LAST)\n\t9. A precious metal (SLIVER) \n\t10. Have belongings (WON) " << endl << endl;
                            break;
                    }
                    cout << "Enter the index of the clue you wish to solve" << endl;            // asking user which clue user wants to solve first .
                    cin >> opt;
                    solution(ch);
                    c[ch-1].check(s, opt);
                    cout << "\n1. Solve another clue\n0. Save and exit" << endl;                // asking user whether to solve another clue.
                    cin >> ch2;
                }
                while(ch2==1);
            }
            cout << "\n1. Solve another crossword\n0. Exit" << endl;                            // asking user whether to solve another crossword
            cin >> ch1;
        }
        while(ch1==1);
    }

    void solution(int ch)                                                                        // class consisting of solution to each crossword
    {
        switch(ch)
        {
            case 1:
                switch(opt)
                {
                    case 1:
                        s = "WORSE";
                        break;
                    case 2:
                        s = "BLEAT";
                        break;
                    case 3:
                        s = "FLOW";
                        break;
                    case 4:
                        s = "ROBE";
                        break;
                    case 5:
                        s = "LEAP";
                        break;
                    case 6:
                        s = "TALE";
                        break;
                    case 7:
                        s = "MEAN";
                        break;
                    case 8:
                        s = "DISEASE";
                        break;
                    case 9:
                        s = "ONCE";
                        break;
                    case 10:
                        s = "PAN";
                        break;
                }
                break;
            case 2:
                switch(opt)
                {
                    case 1:
                        s = "REMOTE";
                        break;
                    case 2:
                        s = "ITEM";
                        break;
                    case 3:
                        s = "ARM";
                        break;
                    case 4:
                        s = "HORSE";
                        break;
                    case 5:
                        s = "ALLERGY";
                        break;
                    case 6:
                        s = "MELON";
                        break;
                    case 7:
                        s = "WASP";
                        break;
                    case 8:
                        s = "BREAD";
                        break;
                    case 9:
                        s = "READ";
                        break;
                    case 10:
                        s = "PLATE";
                        break;
                }
                break;
            case 3:
                switch(opt)
                {
                    case 1:
                        s = "BAKER";
                        break;
                    case 2:
                        s = "MANE";
                        break;
                    case 3:
                        s = "SPACE";
                        break;
                    case 4:
                        s = "DIAPERS";
                        break;
                    case 5:
                        s = "WIDER";
                        break;
                    case 6:
                        s = "DANGER";
                        break;
                    case 7:
                        s = "GLARE";
                        break;
                    case 8:
                        s = "ASLEEP";
                        break;
                    case 9:
                        s = "SEAL";
                        break;
                    case 10:
                        s = "LAIR";
                        break;
                }
                break;
            case 4:
                switch(opt)
                {
                    case 1:
                        s = "COAST";
                        break;
                    case 2:
                        s = "ELBOW";
                        break;
                    case 3:
                        s = "LISTEN";
                        break;
                    case 4:
                        s = "SPELT";
                        break;
                    case 5:
                        s = "EDIT";
                        break;
                    case 6:
                        s = "SERPENT";
                        break;
                    case 7:
                        s = "STEAK";
                        break;
                    case 8:
                        s = "ERA";
                        break;
                    case 9:
                        s = "SOFTER";
                        break;
                    case 10:
                        s = "TRAITS";
                        break;
                }
                break;
                case 5 :
                    switch(opt)
                    {
                    case 1:
                        s = "STEAL";
                        break;
                    case 2:
                        s = "ENLARGE";
                        break;
                    case 3:
                        s = "STAIN";
                        break;
                    case 4:
                        s = "HEART";
                        break;
                    case 5:
                        s = "SHAPE";
                        break;
                    case 6:
                        s = "ALERT";
                        break;
                    case 7:
                        s = "TABLES";
                        break;
                    case 8:
                        s = "SALT";
                        break;
                    case 9:
                        s = "SILVER";
                        break;
                    case 10:
                        s = "OWN";
                        break;
                    }
                    break;
        }
    }
};

int main()
{
    multiple m;
    cout << "\t\t--------------------------------------------\n\t\t\t  LET'S SOLVE ANAGRAMS\n\t\t--------------------------------------------" << endl;
    m.clues();
    cout << "\nYou have successfully exited the game" << endl;
    return 0;
}

/* OUTPUT:
 *
		--------------------------------------------
			  LET'S SOLVE ANAGRAMS
		--------------------------------------------
	Which crossword do you wish to solve?

	1. Crossword 1.
	2. Crossword 2.
	3. Crossword 3.
	4. Crossword 4.
	5. Crossword 5.
	6. Exit
1

		****** CLUES *******

	Current status of the puzzle:

     ___ ___ ___ ___ ___ ___ ___
1.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
1
Enter your answer (IN CAPITALS ONLY)
WORSE

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
5
Enter your answer (IN CAPITALS ONLY)
pale

!! Incorrect answer !!

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
5
Enter your answer (IN CAPITALS ONLY)
LEAP

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
4
Enter your answer (IN CAPITALS ONLY)
ROBE

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
9
Enter your answer (IN CAPITALS ONLY)
ONCE

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
7
Enter your answer (IN CAPITALS ONLY)
MEAN

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  | M | E | A | N |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
0

1. Solve another crossword
0. Exit
1
	Which crossword do you wish to solve?

	1. Crossword 1.
	2. Crossword 2.
	3. Crossword 3.
	4. Crossword 4.
	5. Crossword 5.
	6. Exit
4

		****** CLUES *******

	Current status of the puzzle:

     ___ ___ ___ ___ ___ ___ ___
1.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
1
Enter your answer (IN CAPITALS ONLY)
CAOST

!! Incorrect answer !!

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
1
Enter your answer (IN CAPITALS ONLY)
COAST

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
6
Enter your answer (IN CAPITALS ONLY)
SERPENT

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
7
Enter your answer (IN CAPITALS ONLY)
STEAK

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
10
Enter your answer (IN CAPITALS ONLY)
TRAITS

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
8
Enter your answer (IN CAPITALS ONLY)
ERA

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  | E | R | A |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
0

1. Solve another crossword
0. Exit
1
	Which crossword do you wish to solve?

	1. Crossword 1.
	2. Crossword 2.
	3. Crossword 3.
	4. Crossword 4.
	5. Crossword 5.
	6. Exit
1

		****** CLUES *******

	Current status of the puzzle:

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  | M | E | A | N |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
2
Enter your answer (IN CAPITALS ONLY)
BLEAT

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  | B | L | E | A | T |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  | M | E | A | N |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
10
Enter your answer (IN CAPITALS ONLY)
PAN

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  | B | L | E | A | T |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  | M | E | A | N |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. | P | A | N |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
3
Enter your answer (IN CAPITALS ONLY)
FLOW

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  | B | L | E | A | T |   |   |
    |___|___|___|___|___|___|___|
3.  | F | L | O | W |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
7.  | M | E | A | N |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. | P | A | N |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
6
Enter your answer (IN CAPITALS ONLY)
TALE

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  | B | L | E | A | T |   |   |
    |___|___|___|___|___|___|___|
3.  | F | L | O | W |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  | T | A | L | E |   |   |   |
    |___|___|___|___|___|___|___|
7.  | M | E | A | N |   |   |   |
    |___|___|___|___|___|___|___|
8.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. | P | A | N |   |   |   |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  More than bad (SWORE)
	2.  Sound made by a sheep (TABLE)
	3.  Movement of water (WOLF)
	4.  A long dress (BORE)
	5.  To jump (PALE)
	6.  A story (LATE)
	7.  Average (NAME)
	8.  A sickness (SEASIDE)
	9.  One time (CONE)
	10. Vessel (NAP)

Enter the index of the clue you wish to solve
8
Enter your answer (IN CAPITALS ONLY)
DISEASE

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | W | O | R | S | E |   |   |
    |___|___|___|___|___|___|___|
2.  | B | L | E | A | T |   |   |
    |___|___|___|___|___|___|___|
3.  | F | L | O | W |   |   |   |
    |___|___|___|___|___|___|___|
4.  | R | O | B | E |   |   |   |
    |___|___|___|___|___|___|___|
5.  | L | E | A | P |   |   |   |
    |___|___|___|___|___|___|___|
6.  | T | A | L | E |   |   |   |
    |___|___|___|___|___|___|___|
7.  | M | E | A | N |   |   |   |
    |___|___|___|___|___|___|___|
8.  | D | I | S | E | A | S | E |
    |___|___|___|___|___|___|___|
9.  | O | N | C | E |   |   |   |
    |___|___|___|___|___|___|___|
10. | P | A | N |   |   |   |   |
    |___|___|___|___|___|___|___|

!!!! YOU HAVE COMPLETED THE CROSSWORD. CONGRATULATIONS !!!!

1. Solve another clue
0. Save and exit
0

1. Solve another crossword
0. Exit
1
	Which crossword do you wish to solve?

	1. Crossword 1.
	2. Crossword 2.
	3. Crossword 3.
	4. Crossword 4.
	5. Crossword 5.
	6. Exit
4

		****** CLUES *******

	Current status of the puzzle:

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  | E | R | A |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
5
Enter your answer (IN CAPITALS ONLY)
EDIT

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  | E | D | I | T |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  | E | R | A |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
3
Enter your answer (IN CAPITALS ONLY)
LISTEN

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  | L | I | S | T | E | N |   |
    |___|___|___|___|___|___|___|
4.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
5.  | E | D | I | T |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  | E | R | A |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
4
Enter your answer (IN CAPITALS ONLY)
SPELT

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
3.  | L | I | S | T | E | N |   |
    |___|___|___|___|___|___|___|
4.  | S | P | E | L | T |   |   |
    |___|___|___|___|___|___|___|
5.  | E | D | I | T |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  | E | R | A |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
2
Enter your answer (IN CAPITALS ONLY)
ELBOW

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  | E | L | B | O | W |   |   |
    |___|___|___|___|___|___|___|
3.  | L | I | S | T | E | N |   |
    |___|___|___|___|___|___|___|
4.  | S | P | E | L | T |   |   |
    |___|___|___|___|___|___|___|
5.  | E | D | I | T |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  | E | R | A |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  |   |   |   |   |   |   |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

1. Solve another clue
0. Save and exit
1

	1.  Where land meets sea (COATS)
	2.  A part of your arm (BELOW)
	3.  Try to hear (SILENT)
	4.  Past tense of spell (SLEPT)
	5.  Fix a written work (DIET)
	6.  Another word for snake (PRESENT)
	7.  A piece of beef (SKATE)
	8.  A period of time (EAR)
	9.  Not as hard (FOREST)
	10. Characteristics of something (ARTIST)

Enter the index of the clue you wish to solve
9
Enter your answer (IN CAPITALS ONLY)
SOFTER

!! Correct answer !!

     ___ ___ ___ ___ ___ ___ ___
1.  | C | O | A | S | T |   |   |
    |___|___|___|___|___|___|___|
2.  | E | L | B | O | W |   |   |
    |___|___|___|___|___|___|___|
3.  | L | I | S | T | E | N |   |
    |___|___|___|___|___|___|___|
4.  | S | P | E | L | T |   |   |
    |___|___|___|___|___|___|___|
5.  | E | D | I | T |   |   |   |
    |___|___|___|___|___|___|___|
6.  | S | E | R | P | E | N | T |
    |___|___|___|___|___|___|___|
7.  | S | T | E | A | K |   |   |
    |___|___|___|___|___|___|___|
8.  | E | R | A |   |   |   |   |
    |___|___|___|___|___|___|___|
9.  | S | O | F | T | E | R |   |
    |___|___|___|___|___|___|___|
10. | T | R | A | I | T | S |   |
    |___|___|___|___|___|___|___|

!!!! YOU HAVE COMPLETED THE CROSSWORD. CONGRATULATIONS !!!!

1. Solve another clue
0. Save and exit
0

1. Solve another crossword
0. Exit
0

You have successfully exited the game

 */
