/**
* File: Final Project
* Developer: Yuriy Pishchanetskiy
* Email: ypishchanetskiy@gmail.com
* Description: A Concordance - word: count: line count: line count
*/
// create the word class
// adjective of line
// adjective of count
class Word
{
    public:
        Word(std::string word);//the actual word
        void add_line(int line);// mark the line it is on
        void add_count(int count);// frequency of the word
        void print()const;// what is printed out
    private:
    int m_count;// initialization of the count
    std::string m_word;//initialization of the word
    std::vector<int> m_line;// the vector to hold the line number
};
Word::Word(std::string word)// the actual word
{
    m_word = word;// making the word part of the class
    m_count = 1;// initializing and starting the frequency count
}
void Word::add_count(int count)// function to increment the count
{
    m_count++;// add one to the count for this word
}
void Word::add_line(int line)// function to add the line to the vector
{
    m_line.push_back(line)// adding the line
}
void Word::print()
{
    std::cout << m_word << ": " << m_count << std::endl;//
    for(i = 0; i < m_line.size(); i++)//
    {
        cout << m_line[i] <<  std::endl;// maybe move this to another location in the code. after i have finished all
        // tasks.
    }
}
std::string Word::print_word()
{
    return m_word;
}
    

//creating the class that actually gets and tests the words
// parse actually runs the program
class Concordance
{
    public:
        Concordance(std::string filename);//getting the file you will use
        void parse();// read the file
        std::string next_word(std::ifstream &alice);// getting the next word. param are it reading from the other file. 
        bool is_whitespace(char c);// initialization to check for white spaces dividing the words

        void eat_whitespace(std::ifstream &alice);// forgot what this does
        int find_word(std::string word);// checks for doubles
        void print();// prints out what i have
    private:
        std::vector<Word> index;// the vector for all the words
        std:: string m_filename;// string to bring in the text file
};
Concordance::Concrdance(std::string filename)// initialize the file name
{
    m_filename = filename;
}
void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());// read this file
    while(!file.eof())//while its not the end of file
    {
        for(i = 0; index < i; i++)//
           if(m_word != next_word)//
           {
               m_word = next_word;//
               m_word.push_back(index);//
           }
           std::cout << index  << std::endl;// my attempt to compare the next word to the words in the vector to remove
           // doubles
    }
}
bool Concordance::is_whitespace(char c)// function is to find the words
{
    return (c == ' ' || c == '\n' || c == '\t');
}
void Concordance::eat_whitespace(std::ifstream& alice)
{
    for(;;)
    {
        char c; 
        alice.get(c);
        if(alice.eof())
            break;
            if(!is_whitespace(c))
            {
                alice.putback(c);
                break;
            }
    }
}
std::string Concordance::next_word(std::ifstream& alice)
{
    std::string word;
    for(;;)
    {
        char c
        alice.get(c);
        if(alice.eof())
            break;
            if(!is_whitespace(c))//building the words one character at a time
            {
                word += c;
            }
            else
            {
                eat_whitespace(alice);
                break;
            }
    }
    return word;
}
void Concordance::print()
{
    for (i = 0; i<index.size(); i++)
    {
        index[i].print();
    }

}
int main()
{
    Concordance con("aliice.txt");
    con.parse();
    con.print();

    return 0;
}
