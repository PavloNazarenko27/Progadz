import java.util.ArrayList;
import java.util.List;

public class Main {
    static class Word {
        private String value;
        Word(String value) { this.value = value; }
        public String getValue() { return value; }
    }

    static class Sentence {
        private List<Word> words = new ArrayList<>();
        void addWord(Word word) { words.add(word); }
        public String getValue() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < words.size(); i++) {
                sb.append(words.get(i).getValue()).append(i == words.size() - 1 ? "" : " ");
            }
            return sb.toString();
        }
    }

    static class Text {
        private String title;
        private List<Sentence> sentences = new ArrayList<>();

        Text(String title) { this.title = title; }
        void addSentence(Sentence sentence) { sentences.add(sentence); }
        void printTitle() { System.out.println("Заголовок: " + title); }
        void printText() {
            for (Sentence s : sentences) {
                System.out.print(s.getValue() + ". ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Text text = new Text("Java ООП");
        Sentence s1 = new Sentence();
        s1.addWord(new Word("Це"));
        s1.addWord(new Word("перше"));
        s1.addWord(new Word("речення"));
        text.addSentence(s1);

        text.printTitle();
        text.printText();

        Sentence s2 = new Sentence();
        s2.addWord(new Word("Це"));
        s2.addWord(new Word("друге"));
        s2.addWord(new Word("речення"));
        text.addSentence(s2);

        text.printText();
    }
}