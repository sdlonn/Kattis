public class HighScore {

    public static byte lowest = (byte) 'A';
    public static byte mid = (byte) 'N';
    public static byte highest = (byte) 'Z';
    public static KattioHelper io = new KattioHelper(System.in, System.out);

    public static void main(String[] args) {
        int stop = io.getInt();
        for (int i = 0; i < stop; i++) {
            io.println(doWork(io.getWord().getBytes()));
        }
        io.close();
    }

    private static int doWork(byte[] word) {
        int totalMoves = 0;
        int wordLength = word.length;
        for (byte b : word) {
            totalMoves += getMinimumAmountOfMovesToGetChar(b);
        }

        return (totalMoves + getSideMoves(word, wordLength));
    }
    private static int getSideMoves(byte[] word, int wordLength){
        int tempMoves = wordLength - 1;

        for(int i = 0; i < wordLength; i++) {
            int tmp = findAndGetLastIndexOfNextGroupOfAIfNextCharIsA(word, i, wordLength);
            if(tmp > i){
                tempMoves = getLowestNumber(((i + i) + ((wordLength - tmp) - 1)), ((((wordLength - tmp) - 1) * 2) + (i)), tempMoves);
                i = tmp;
            }
        }
        return tempMoves;
    }

    private static int getMinimumAmountOfMovesToGetChar(byte ch) {
        return (ch < mid) ? (ch - lowest): ((highest + 1) - ch);
    }

    private static int getLowestNumber(int a, int b, int c){
        return a < b ? (Math.min(a, c)) : (Math.min(b, c));
    }

    private static int findAndGetLastIndexOfNextGroupOfAIfNextCharIsA(byte[] word, int currentIndex, int wordLength){
        return (currentIndex < wordLength - 1) && (word[currentIndex + 1] == lowest) ? findAndGetLastIndexOfNextGroupOfAIfNextCharIsA(
                word, currentIndex + 1, wordLength) : currentIndex;
    }
}
