class BookMyShow {

      private int lo = 0;
        private final int m;
        private final int[] sits;

    public BookMyShow(int n, int m) {
        this.m = m; sits = new int[n]; Arrays.fill(sits, m);
    }
    
    public int[] gather(int k, int maxRow)  {
            for (int i = lo; i <= maxRow; i++) {
                if (k <= sits[i]) {
                    sits[i] -= k;
                    return new int[]{i, m - sits[i] - k};
                }
            }
            return new int[]{};
        }
    
    public boolean scatter(int k, int maxRow) {
            int idx = lo;
            while (idx <= maxRow && k > sits[idx]) k -= sits[idx++];
            if (idx > maxRow && k > 0) return false;

            sits[idx] -= k;
            lo = idx;

            return true;
        }
    
}