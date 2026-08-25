class Solution {
public:

    unordered_map<string, double> bfs(string start,unordered_map<string, vector<pair<string, double>>> &graph
    )
    {
        queue<pair<string, double>> q;
        unordered_map<string, double> amount;

        q.push({start, 1.0});
        amount[start] = 1.0;

        while (!q.empty())
        {
            auto [node, currAmount] = q.front();
            q.pop();

            for (auto &[child, rate] : graph[node])
            {
                if (amount.count(child))
                    continue;

                double newAmount = currAmount * rate;

                amount[child] = newAmount;
                q.push({child, newAmount});
            }
        }

        return amount;
    }

    double maxAmount(string initialCurrency,vector<vector<string>>& pairs1,vector<double>& rates1,vector<vector<string>>& pairs2,vector<double>& rates2
    )
    {
        unordered_map<string, vector<pair<string, double>>> graph1;
        unordered_map<string, vector<pair<string, double>>> graph2;

        for (int i = 0; i < pairs1.size(); i++)
        {
            string a = pairs1[i][0];
            string b = pairs1[i][1];

            double rate = rates1[i];

            graph1[a].push_back({b, rate});
            graph1[b].push_back({a, 1.0 / rate});
        }

        for (int i = 0; i < pairs2.size(); i++)
        {
            string a = pairs2[i][0];
            string b = pairs2[i][1];

            double rate = rates2[i];

            graph2[a].push_back({b, rate});
            graph2[b].push_back({a, 1.0 / rate});
        }

        auto day1 = bfs(initialCurrency, graph1);

        double ans = 1.0;

        for (auto &[currency, amount] : day1)
        {
            auto day2 = bfs(currency, graph2);

            if (day2.count(initialCurrency))
            {
                ans = max(ans,amount * day2[initialCurrency]
                );
            }
        }

        return ans;
    }
};