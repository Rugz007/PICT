#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value, weight;
    Item()
    {
        value = 0;
        weight = 0;
    }
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};
class KnapSack
{
    Item items[10];
    int W;
    int number_of_items;

public:
    bool static compare(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack()
    {
        sort(items, items + number_of_items, compare);
        int curWeight = 0;
        double finalvalue = 0.0;
        for (int i = 0; i < number_of_items; i++)
        {
            if (curWeight + items[i].weight <= W)
            {
                curWeight += items[i].weight;
                finalvalue += items[i].value;
            }
            else
            {
                int remain = W - curWeight;
                finalvalue += items[i].value * ((double)remain / (double)items[i].weight);
                break;
            }
        }
        cout << "Final Value" << finalvalue;
        return finalvalue;
    }
    void input()
    {
        int value, weight;
        cout << "Enter number of items : ";
        cin >> number_of_items;
        cout << "Enter total capacity:- ";
        cin >> W;
        cout << "Enter Value/Weight \n";
        for (int i = 0; i < number_of_items; ++i)
        {
            cout << i + 1 << " value";
            cin >> value;
            cin >> weight;
            Item item = Item(value, weight);
            items[i] = item;
        }
    }
};
int main()
{
    KnapSack sack;
    sack.input();
    sack.fractionalKnapsack();
    return 0;
}