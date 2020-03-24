
class solution {
	double minCostKWorker(vector<int> &quality, vector<int> &wage, int k) {
		int n = quality.size();
		double res = DBL_MAX;
		double qsum = 0;
		vector<pair<double,int>> worker;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++)
			worker.push_back(make_pair{wage[i]/quality[i], quality});

		for (auto worker:workers) {
			qsum += worker.second;
			pq.push(second);
			if (k > pq.size() {
				qsum -= pq.top();
				pq.pop();		
			}
			if (k == pq.size())
				res = min(res, worker.first * qsum);
		}
	}
}
