import java.util.Arrays;

/*
Runtime-10 ms
Memory-53.2 MB
 */
public class assign_cookies {
    public int findContentChildren(int[] g, int[] s) {
        if(s.length==0) return 0;
        Arrays.sort(g);
        Arrays.sort(s);
        int child=g.length-1;
        int cookie=s.length-1;
        int content=0;
        for(;cookie>=0 && child>=0;child--){
            if(s[cookie]>=g[child]){
                content++;
                cookie--;
            }
        }
        return content;

    }
}
