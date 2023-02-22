/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

Input
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]
*/

class StockSpanner
{
public:
    stack<pair<int, int>> st; // <price,span>
    int next(int price)
    {
        // Approach is simillar to Next Greater Element
        pair<int, int> curr = {price, 1}; // Initially storing span as 1
        while (!st.empty() && st.top().first <= price)
        {
            curr.second += st.top().second; // Adding span of all days which has lower price than curr
            st.pop();
        }

        st.push(curr);

        return curr.second;
    }
};