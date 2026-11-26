#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *wordList[] = {
         "an", "am", "as", "at", "be", "by", "do", "go", "he", "if",
         "in", "is", "it", "me", "my", "no", "of", "on", "or", "ox",
         "so", "to", "up", "us", "we", "ad", "ah", "aw", "ax", "ay",
         "eh", "em", "en", "er", "ex", "ha", "hi", "ho", "id", "jo",
         "ka", "la", "ma", "mm", "oh", "oi", "om", "ow", "oy", "uh",

         "ace", "act", "add", "age", "ago", "air", "all", "and", "ant", "any",
         "ape", "are", "arm", "art", "ash", "ask", "bad", "bag", "ban", "bar",
        "bat", "bed", "bee", "beg", "bet", "big", "bit", "bow", "box", "boy",
        "bus", "buy", "can", "cap", "car", "cat", "cow", "cry", "cup", "cut",
        "day", "den", "dew", "die", "dig", "dog", "dry", "ear", "eat", "egg",

       "able", "acid", "aged", "also", "area", "army", "away", "baby", "back", "bake",
       "ball", "band", "bank", "base", "bath", "bear", "beat", "been", "bell", "belt",
       "best", "bird", "blue", "boat", "body", "book", "born", "both", "bowl", "busy",
       "call", "calm", "came", "camp", "card", "care", "cart", "case", "cash", "city",
       "club", "coat", "cold", "come", "cook", "cool", "copy", "dark", "data", "date",

       "about", "above", "actor", "admit", "adopt", "adult", "after", "again", "agent", "agree",
       "ahead", "alarm", "album", "alert", "alien", "alive", "allow", "alone", "along", "angel",
       "anger", "angle", "angry", "apart", "apple", "apply", "arena", "argue", "arise", "array",
       "aside", "audio", "avoid", "award", "aware", "badly", "basic", "beach", "began", "begin",
       "being", "below", "bench", "birth", "black", "blame", "blank", "blind", "block", "blood"

    };

    char target[500] = "";
    char typed[500];

    int totalWords = 10;
    int totalAvailable = sizeof(wordList) / sizeof(wordList[0]);

    int i, correct = 0;
    int typedWords = 0;
    int targetLength, typedLength;
    int maxLength;

    double seconds, wpm, accuracy;

    time_t start, end;

    srand((unsigned int)time(NULL));

    printf("\n====================================\n");
    printf("       RANDOM TYPING SPEED TEST\n");
    printf("====================================\n");

    printf("\nType these random words:\n\n");

    for(i = 0; i < totalWords; i++)
    {
        int randomIndex = rand() % totalAvailable;

        strcat(target, wordList[randomIndex]);
        strcat(target, " ");
    }

    target[strlen(target) - 1] = '\0';

    printf("%s\n", target);

    printf("\nStart typing:\n");

    start = time(NULL);

    fgets(typed, sizeof(typed), stdin);

    end = time(NULL);

    typed[strcspn(typed, "\n")] = '\0';

    seconds = difftime(end, start);

    targetLength = strlen(target);
    typedLength = strlen(typed);

    for(i = 0; i < typedLength; i++)
    {
        if(typed[i] != ' ' &&
           (i == 0 || typed[i - 1] == ' '))
        {
            typedWords++;
        }
    }

    maxLength = targetLength > typedLength ?
                targetLength : typedLength;

    for(i = 0; i < targetLength && i < typedLength; i++)
    {
        if(target[i] == typed[i])
        {
            correct++;
        }
    }

    if(seconds <= 0)
        seconds = 1;

    wpm = (typedWords * 60.0) / seconds;

    if(maxLength == 0)
        accuracy = 0;
    else
        accuracy = (correct * 100.0) / maxLength;

    printf("\n====================================\n");
    printf("             YOUR RESULTS\n");
    printf("====================================\n");

    printf("\nTime Taken : %.0f seconds", seconds);
    printf("\nWords Typed : %d", typedWords);
    printf("\nTyping Speed : %.2f WPM", wpm);
    printf("\nAccuracy : %.2f%%", accuracy);

    if(accuracy >= 90)
        printf("\nPerformance : EXCELLENT!");
    else if(accuracy >= 70)
        printf("\nPerformance : GOOD!");
    else
        printf("\nPerformance : KEEP PRACTICING!");

    printf("\n====================================\n");

    return 0;
}
