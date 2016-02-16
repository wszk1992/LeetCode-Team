# @param {Integer[]} citations
# @return {Integer}
def h_index(citations)
    h=0
    citations.sort!
    citations.each_index{|x| 
    if(citations[x]>=citations.length-x) 
        h = citations.length-x
        return h
    end
    }
end
