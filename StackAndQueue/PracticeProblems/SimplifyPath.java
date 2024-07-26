import java.util.Arrays;
import java.util.Stack;

public class SimplifyPath {

    public String[] splitPath(String path){
        return path.split("/");
    }

    public String simplifyPath(String path) {
        if(path.equals("/../") || path.equals("/")) return "/";
        String arr[] = splitPath(path);
        if(path.trim().isEmpty() || arr.length == 0) return "/";
        Stack<String> stack = new Stack<>();
        for(String str : arr){
            if(str.equals("..")){
                if(stack.isEmpty()) continue;
                else stack.pop();
            }else if(str.equals(".") || str.isEmpty()){
                continue;
            }else{
                str = "/" + str;
                stack.push(str);
            }
        }

        String res = "";
        for(String element : stack){
            res = res.concat(element);
        }
        return res.isEmpty() ? "/" : res;
    }


    public static void main(String[] args) {
        String path = "/.";
        SimplifyPath ob = new SimplifyPath();
        System.out.println(Arrays.toString(ob.splitPath(path)));
        String res = ob.simplifyPath(path);
        System.out.println(res);
    }
}

// Problems faced:
/*
* Error while handling singular dots with no other paths mentioned
* Handling empty paths
* Stack memory error for popping when empty
* Error for multiple / : ///
* Pre handling strings can cause error
* */