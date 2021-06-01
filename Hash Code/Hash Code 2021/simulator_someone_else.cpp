#include <bits/stdc++.h>
using namespace std;

struct street_info { int B, E, L, period_length, green_start, green_end; };
struct event { int timestamp, car_id; };
bool operator< (const event &A, const event &B) { if (A.timestamp != B.timestamp) return A.timestamp < B.timestamp; else return A.car_id < B.car_id; }

int D, I, S, V, F, A;
unordered_map<string,int> street_id;
vector<string> reverse_street_id;
vector<street_info> streets;
vector< vector<int> > car_paths;
vector< queue<int> > traffic_lights;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int file_number=0; file_number<1000; file_number++) {
        street_id.clear();
        reverse_street_id.clear();
        streets.clear();
        car_paths.clear();
        traffic_lights.clear();

        freopen("d.txt", "r", stdin);
        cin >> D >> I >> S >> V >> F;

        for (int s=0; s<S; ++s) {
            int b, e, l; string label;
            cin >> b >> e >> label >> l;
            street_id[label] = s;
            streets.push_back( {b,e,l,1,0,0} );
            reverse_street_id.push_back(label);
        }

        traffic_lights.resize(S);

        for (int v=0; v<V; ++v) {
            vector<int> path;
            int P;
            cin >> P;
            string label;
            while (P--) { cin >> label; path.push_back( street_id[label] ); }
            car_paths.push_back(path);
            traffic_lights[path[0]].push(v);
        }

        //output file.
        char title[8];
        sprintf(title, "d%d.txt", file_number);
        freopen(title, "r", stdin);

        cin >> A;
        for (int a=0; a<A; ++a) {
            int intersection;
            cin >> intersection;
            int E;
            cin >> E;
            vector<int> street_order;
            vector<int> times;
            int total_time = 0;
            for (int e=0; e<E; ++e) {
                string label; int t;
                cin >> label >> t;
                int str = street_id[label];
                street_order.push_back(str);
                times.push_back(t);
                total_time += t;
            }
            int cur_time = 0;
            for (int e=0; e<E; ++e) {
                int str = street_order[e];
                streets[str].period_length = total_time;
                streets[str].green_start = cur_time;
                cur_time += times[e];
                streets[str].green_end = cur_time;
            }
        }

        set<event> future_events;
        vector<int> car_path_segment(V, 0);

        set<int> streets_with_waiting_cars;
        for (int s=0; s<S; ++s) if (!traffic_lights[s].empty()) streets_with_waiting_cars.insert(s);

        int SCORE = 0;

        for (int timestamp = 0; timestamp <= D; ++timestamp) {
            while (!future_events.empty() && future_events.begin()->timestamp == timestamp) {
                int car = future_events.begin()->car_id;
                future_events.erase( future_events.begin() );
                int cps = car_path_segment[car];
                if (cps == int(car_paths[car].size())-1) SCORE += F + (D - timestamp); else {
                    int str = car_paths[car][cps];
                    traffic_lights[str].push(car);
                    streets_with_waiting_cars.insert(str);
                }
            }

            vector<int> emptied_streets;
            if (timestamp == D) break;
            for (int s : streets_with_waiting_cars) {

                int ts = (streets[s].period_length == 0 ? -1 : timestamp % streets[s].period_length);
                if (ts < streets[s].green_start || ts >= streets[s].green_end) continue;

                int car = traffic_lights[s].front();
                traffic_lights[s].pop();
                if (traffic_lights[s].empty()) emptied_streets.push_back(s);

                ++car_path_segment[car];
                int str = car_paths[car][ car_path_segment[car] ];
                future_events.insert( {timestamp + streets[str].L, car} );
            }
            for (int s : emptied_streets) streets_with_waiting_cars.erase(s);
        }
        if (SCORE>1590000) {
            cout << "SCORE: " << file_number <<" " << SCORE << endl;
        }
    }
}
