#include <iostream>
#include <vector>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

vector<string> transitive_verbs = {
    "brings", "buys", "builds", "carries", "catches", "chooses", "cleans", "closes", "cooks", "cuts",
    "draws", "drinks", "drives", "eats", "fixes", "gives", "grabs", "helps", "hits", "holds",
    "keeps", "kicks", "knows", "lends", "likes", "loves", "makes", "moves", "opens", "paints",
    "passes", "pays", "plays", "reads", "repairs", "sends", "shows", "sings", "takes", "teaches",
    "tells", "throws", "touches", "uses", "wants", "watches", "writes", "feeds", "gathers", "holds"
};
vector<string> object_nouns = {
    "A book", "A car", "A house", "A phone", "A computer", "A shirt", "A bag", "A pen", "A ball", "A chair",
    "A table", "A bike", "A hat", "A shoe", "A lamp", "A door", "A window", "A key", "A wallet", "A watch",
    "A picture", "A bed", "A sofa", "A plant", "A cup", "A plate", "A spoon", "A fork", "A knife", "A glass",
    "A bottle", "A notebook", "A pencil", "A box", "A toy", "A guitar", "A camera", "A mirror", "A clock", "A fan",
    "A remote", "A pair of headphones", "A pair of scissors", "A laptop", "A tablet", "A brush", "A broom", "A phone", "A candle", "A basket"
};

vector<string> subject_nouns = {
    "A dog",
    "A cat",
    "A child",
    "A teacher",
    "A doctor",
    "An artist",
    "An engineer",
    "A student",
    "A driver",
    "A chef",
    "A friend",
    "A parent",
    "A singer",
    "A dancer",
    "An athlete",
    "An actor",
    "A writer",
    "A scientist",
    "A farmer",
    "A pilot",
    "A nurse",
    "An officer",
    "A worker",
    "An inventor",
    "A leader",
    "A professor",
    "A musician",
    "A designer",
    "An architect",
    "A painter",
    "A neighbor",
    "A tourist",
    "A visitor",
    "A manager",
    "A librarian",
    "A salesperson",
    "A technician",
    "A consultant",
    "A researcher",
    "A gardener",
    "A firefighter",
    "An astronaut",
    "A lawyer",
    "A veterinarian",
    "A plumber",
    "A coach",
    "A photographer",
    "A blogger",
    "A reporter",
    "An actor"
}; 

vector<string> time_place = {
    "At the park in the morning.",
    "At the school in the afternoon.",
    "In the library in the evening.",
    "At the restaurant at night.",
    "At the mall at noon.",
    "On the beach at midnight.",
    "At the hospital yesterday.",
    "At the airport today.",
    "At the train station tomorrow morning.",
    "At the bus stop in the early afternoon.",
    "In the office last week.",
    "At home this weekend.",
    "At the cinema last night.",
    "At the zoo on a sunny Saturday.",
    "In the museum yesterday.",
    "At the stadium last month.",
    "At the theater last year.",
    "At the grocery store this morning.",
    "At the cafe at lunchtime.",
    "At the hotel last night.",
    "At the university on Monday.",
    "At the gym in the evening.",
    "In the swimming pool yesterday.",
    "At the playground in the afternoon.",
    "At the bakery this morning.",
    "At the pharmacy yesterday.",
    "At the market early in the morning.",
    "At the church last Sunday.",
    "At the temple last Friday.",
    "At the mosque at dawn.",
    "At the bank yesterday.",
    "At the post office today.",
    "At the court last year.",
    "At the police station yesterday.",
    "At the fire station last month.",
    "In the garden this afternoon.",
    "In the forest during spring.",
    "In the mountains last summer.",
    "By the river in the morning.",
    "By the lake last weekend.",
    "On the bridge at sunset.",
    "In the tower at dusk.",
    "At the castle last year.",
    "At the factory yesterday.",
    "In the warehouse last Monday.",
    "At the amusement park last holiday.",
    "In the concert hall last night.",
    "At the art gallery last Saturday.",
    "In the aquarium last weekend.",
    "At the campground last summer."
};


void sent(){
    int count = 0;
    while(count < 5){
    srand(time(0));
    int random = rand() % (50 - count);
    string sentence = subject_nouns[random] +" "+ transitive_verbs[random] +" "+ object_nouns[random] +" "+ time_place[random];
    cout << endl << sentence << endl;
    cout << "Enter each word in the sentence above: \n";
    string ans;
    int score = 100;
    int seconds = 8;
    cout << "You have 8 seconds to write the sentence\n";
    cout << "Press enter to continue...." << endl;
    cin.ignore();
    // cin.get();
    // sleep(5);
  
    
    
    auto start_time = chrono::steady_clock::now();
    getline(cin, ans);
    auto end_time = chrono::steady_clock::now();

    if (chrono::duration_cast<chrono::seconds>(end_time - start_time).count() > 8) {
            cout << "Time's up! \n";
            score -= 50;
        } 
    for (size_t i = 0; i < sentence.size(); i++) {
        if (tolower(sentence[i]) != tolower(ans[i])) {
            score -= 5;
            }
        }
        
    cout << score;
    subject_nouns.erase(subject_nouns.begin() + random);
    transitive_verbs.erase(transitive_verbs.begin() + random);
    object_nouns.erase(object_nouns.begin() + random);
    time_place.erase(time_place.begin() + random);
    count++;
    }
}

int main(){
    sent();
    

}