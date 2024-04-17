import java.util.regex.Pattern;
import java.util.regex.MatchResult;

public class CalcRegex{
  public static void confirmAlive(){
    System.out.println("Java CalcRegex helper is alive!");
  }

  public static String replaceAll(String string, String pattern, String replace){
    return string.replaceAll(pattern, replace);
  }

  public static String[] getMatches(String string, String pattern){
    return Pattern.compile(string)
        .matcher(pattern)
        .results()
        .map(MatchResult::group)
        .toArray(String[]::new);
  }
}