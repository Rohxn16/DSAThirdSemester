import java.util.Scanner;
import java.util.Stack;

public class ValidParenthesis {

    boolean isValid(String s){
        Stack<Character> stack = new Stack<>();
        for(char ch : s.toCharArray()){
            if(ch == '[' || ch == '(' || ch == '{'){
                stack.push(ch);
            }else if(ch == ']' || ch == '}' || ch == ')'){
                if(stack.isEmpty()) return false;
                else if ((stack.peek() == '{' && ch == '}') || (stack.peek() == '[' && ch == ']') || stack.peek() == '(' && ch == ')') {
                    stack.pop();
                }else return false; // this is a failsafe, ie for test cases like these ([)
            }
        }
        return stack.isEmpty();
    }

    void solve(){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();
        boolean result = isValid(s);
        System.out.println(result);
    }

    public static void main(String[] args) {
        ValidParenthesis ob = new ValidParenthesis();
        ob.solve();
    }
}
