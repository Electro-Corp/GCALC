import java.util.regex.Pattern;
import java.util.regex.MatchResult;

public class CalcRegex{
  public static void main(String[] args){
    
  }
  public static void confirmAlive(){
    System.out.println("Java CalcRegex helper is alive!");
  }

  public static String replaceAll(String string, String pattern, String replace){
    try{
      string.replaceAll(pattern, replace);
    }catch (Exception e){
      e.printStackTrace();
    }
    return string;
  }

  public static String[] getMatches(String string, String pattern){
    return Pattern.compile(string)
        .matcher(pattern)
        .results()
        .map(MatchResult::group)
        .toArray(String[]::new);
  }
}