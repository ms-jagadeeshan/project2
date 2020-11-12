  //return value =>101, User entered valid word and have no repetition
  //return value =>102, User entered non-vaid word 
  //return value =>103, User entered value is valid but have letter repetition
  //return value =>104, User entered less than four letters 
  //return value =>105, User entered more than four letters

#include<iostream>
#include<cstring>
using namespace std;
int issame(string ,string );      //fucncton to check both words are same
void analyse(string,string,int &,int &);   //function to give cow and goat values
int isvalid(string);
int isrepeat(string);
int main()
{
    top:
    string words[]={"able","acid","aged","also","area","army","away","back","band","bank","base","bath","bear",
    "beat","belt","best","bird","blow","blue","boat","body","bond","bone","born","both","bowl","bulk","burn",
    "bush","busy","calm","came","camp","card","care","case","cash","cast","chat","chip","city","club","coal",
    "coat","code","cold","come","cope","copy","core","cost","crew","crop","dark","date","dawn","days","deal",
    "dean","dear","debt","deny","desk","dial","diet","disc","disk","does","done","dose","down","draw","drew",
    "drop","drug","dual","duke","dust","duty","each","earn","east","easy","evil","exit","face","fact","fail",
    "fair","farm","fast","fate","fear","felt","file","film","find","fine","fire","firm","fish","five","flat",
    "flow","ford","form","fort","four","from","fuel","fund","gain","game","gate","gave","gear","gift","girl",
    "give","glad","goal","goes","gold","golf","gone","gray","grew","grey","grow","gulf","hair","half","hand",
    "hang","hard","harm","hate","have","head","hear","heat","held","help","hero","hire","hold","hole","holy",
    "home","hope","host","hour","huge","hung","hunt","hurt","idea","inch","into","iron","item","jack","jane",
    "jean","john","join","jump","jury","just","keen","keep","kent","kept","kick","kill","kind","king","knee",
    "knew","know","lack","lady","laid","lake","land","lane","last","late","lead","left","less","life","lift",
    "like","line","link","list","live","load","loan","lock","logo","long","look","lord","lose","loss","lost",
    "love","luck","made","mail","main","make","male","many","Mark","mass","matt","meal","mean","meat","meet",
    "menu","mere","mike","mile","milk","mill","mind","mine","mode","more","most","move","much","must","name",
    "navy","near","neck","news","next","nice","nick","nose","note","okay","once","only","open","oral","over",
    "pace","pack","page","paid","pain","pair","palm","park","part","past","path","peak","pick","pink","pipe",
    "plan","play","plot","plug","plus","rate","read","real","rely","rent","rest","rice","rich","ride","ring",
    "rise","risk","road","rock","role","rose","rule","rush","ruth","safe","said","sake","sale","salt","same",
    "sand","save","seat","self","send","sent","sept","ship","shop","shot","show","shut","sick","side","sign",
    "site","size","skin","slip","slow","snow","soft","soil","sold","sole","some","song","sort","soul","spot",
    "star","stay","step","stop","such","suit","sure","take","tale","talk","tank","tape","task","team","tech",
    "tend","term","test","text","than","them","then","they","thin","this","thus","time","tiny","told","tone",
    "tony","tour","town","trip","true","tune","turn","twin","type","unit","upon","used","user","vary","vast",
    "very","vice","view","vote","wage","wait","wake","walk","want","ward","warm","wash","wave","ways","weak",
    "wear","went","west","what","when","whom","wide","wife","wild","wind","wine","wing","wire","wise","wish",
    "with","word","wore","work","yard","yeah","year","your","zero","zone"};


    printf("\t\tINSTRUCTIONS\n");
    cout<<"1.You shoud give the four letters word and word should be meaningful.\n";
    cout<<"2.All the four letters in the word should be distinct.\n";
    cout<<"3.Terminologies involved\n";
    cout<<"     =>if GOAT=n, then n letter in your word is correct and lies in correct place.\n";
    cout<<"     =>if COW=n, then n letters in your word are correct and lie in wrong place.\n";
    cout<<"\t    eg.if your word is love and answer is wolf \n";
    cout<< "\t       goat=1  cow=1\n";
    cout<<"4.Press 'q' to quit the game.\n";
    cout<<"5.Press 'n' for enter into new game.\n";
    cout<<"6.Press Enter key to enter into the game.\n";
    cin.get();
    cout<<"\t\t    WELCOME!\n"<<"\t         Enter the word\n";
    srand((unsigned) time(0));
     int randomNumber = rand();
     int nthelement=(int)randomNumber%500;
    int i=1;
    string assigned=words[nthelement];
    string playerinput;
    //cout<<assigned;
    int goat=0,cow=0;
    int flag1=0;
    while(flag1==0)
    {       
        whiletop:
        cout<<i<<')';
        cin>>playerinput;
        if(playerinput[0]=='q'&&playerinput.length()==1)
        {
           break; 
        }
        if(playerinput[0]=='n'&&playerinput.length()==1)
        { 
            cout << "\033[2J\033[1;1H";
            goto top;
        }
        int rv;      //rv - return value
        rv=isvalid(playerinput);
        switch (rv)
        {
            case 101 :{i++;  
               
                int flag2;
                flag2=issame(assigned,playerinput);
                if(flag2==1)
                {   flag1=1;
                    cout<<"\tCONGRADULATIONS! YOU WON !!!!!\n";  
                    break;
                }
                else
                {
                    analyse(assigned,playerinput,goat,cow);
                    printf("goat=%d,cow=%d\n\n",goat,cow);
                    cow=0;
                    goat=0;
                }
            }break;

            case 102 :{
                printf("Error %d : \"%c%c%c%c\" is not a Meaningful word.... Try again.....\n",rv,playerinput[0],playerinput[1],playerinput[2],playerinput[3]);
                goto whiletop;
            }break;

            case 103 :{
                printf("Error %d : \"%c%c%c%c\" have repetition of letters....   Try again......\n",rv,playerinput[0],playerinput[1],playerinput[2],playerinput[3]);
                goto whiletop;
            }break;
            
            case 104 :{
                printf("Error %d : Entered word has less than four letters...  Try again....\n",rv);
                goto whiletop;
            }break;

            case 105 :{
                printf("Error %d : Entered word has more than four letters.... Try again.....\n",rv);
                goto whiletop;
            }break;

        }
    }
}
int isrepeat(string s1)
{
    for ( int i=0 ; i<4 ; i++ )
    {
        for ( int j=0 ; j<4 ; j++ )
        {
            if ( i==j )
            {
                continue;
            }

            if ( s1[i]==s1[j] )
            {
                return 103;
                break;
            }
        }       
    }
    return 101;
}

int issame(string s1,string s2)     
{   
    //s1 is what we assigned and s2 is what user given
    int rvalue=1;
    for ( int i=0;i<4;i++ )
    {
        if ( s1[i]!=s2[i] )
        {   
           rvalue=0;
           break;
        }
    }
    return rvalue;
    //if both strings are not same returns f and incase of same returns 1
}

void analyse(string s1,string s2,int &goat,int &cow)
{
    //s1 is what we assigned and s2 is what user given
    for(int i=0;i<4;i++)
    {
        if ( s1[i]==s2[i] )
        {
            goat++;
        }
       
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(s1[i]==s2[j])
            {
                cow++;

          }

        }
    }
}

int isvalid(string s1)
{      
    string validwords [][500]={
        {"aahs","aals","abac","abas","abba","abbe","abbs","abed","abet","abid","able","ably","abos","abri","abut","abye","abys","acai","acca","aced","acer","aces","ache","achy","acid","acme","acne","acre","acta","acts","acyl","adaw","adds","addy","adit","ados","adry","adze","aeon","aero","aery","aesc","afar","affy","afro","agar","agas","aged","agee","agen","ager","ages","agha","agin","agio","aglu","agly","agma","agog","agon","ague","ahed","ahem","ahis","ahoy","aias","aide","aids","aiga","ails","aims","aine","ains","airn","airs","airt","airy","aits","aitu","ajar","ajee","aked","akee","akes","akin","alae","alan","alap","alar","alas","alay","alba","albe","albs","alco","alec","alee","alef","ales","alew","alfa","alfs","alga","alif","alit","alko","alky","alls","ally","alma","alme","alms","alod","aloe","alow","alps","also","alto","alts","alum","amah","amas","ambo","amen","amia","amid","amie","amin","amir","amis","amla","ammo","amok","amps","amus","amyl","anal","anan","anas","ance","ands","anes","anew","anga","anil","anis","ankh","anna","anno","anns","anoa","anon","anow","ansa","anta","ante","anti","ants","anus","apay","aped","aper","apes","apex","apod","apos","apps","apse","apso","apts","aqua","arak","arar","arba","arbs","arch","arco","arcs","ards","area","ared","areg","ares","aret","arew","arfs","aria","arid","aril","aris","arks","arle","arms","army","arna","arow","arpa","arse","arsy","arti","arts","arty","arum","arvo","aryl","asar","asci","asea","ashy","asks","asps","atap","ates","atma","atoc","atok","atom","atop","atua","aufs","auks","aula","auld","aune","aunt","aura","auto","aval","avas","avel","aver","aves","avid","avos","avow","away","awdl","awed","awee","awes","awls","awns","awny","awol","awry","axal","axed","axel","axes","axil","axis","axle","axon","ayah","ayes","ayin","ayre","ayus","azan","azon","azym"},
        {"baal","baas","baba","babe","babu","baby","bach","back","bacs","bade","bads","bael","baff","baft","bagh","bags","baht","bail","bait","baju","bake","bald","bale","balk","ball","balm","bals","balu","bams","banc","band","bane","bang","bani","bank","bans","bant","baps","bapu","barb","bard","bare","barf","bark","barm","barn","barp","bars","base","bash","bask","bass","bast","bate","bath","bats","batt","baud","bauk","baur","bawd","bawl","bawn","bawr","baye","bays","bayt","bead","beak","beam","bean","bear","beat","beau","beck","bede","beds","bedu","beef","been","beep","beer","bees","beet","bego","begs","bein","bell","bels","belt","bema","bend","bene","beni","benj","bens","bent","bere","berg","berk","berm","best","beta","bete","beth","bets","bevy","beys","bhat","bhel","bhut","bias","bibb","bibs","bice","bide","bidi","bids","bien","bier","biff","biga","bigg","bigs","bike","bile","bilk","bill","bima","bind","bine","bing","bink","bins","bint","biog","bios","bird","birk","birl","biro","birr","bise","bish","bisk","bist","bite","bito","bits","bitt","bize","blab","blad","blae","blag","blah","blam","blat","blaw","blay","bleb","bled","blee","blet","blew","bley","blin","blip","blob","bloc","blog","blot","blow","blub","blue","blur","boab","boak","boar","boas","boat","boba","bobs","bock","bode","bods","body","boep","boet","boff","bogs","bogy","boho","bohs","boil","bois","boke","boko","boks","bola","bold","bole","boll","bolo","bolt","boma","bomb","bona","bond","bone","bong","bonk","bony","boob","booh","book","bool","boom","boon","boor","boos","boot","bops","bora","bord","bore","bork","borm","born","bors","bort","bosh","bosk","boss","bota","both","bots","bott","bouk","boun","bout","bowl","bowr","bows","boxy","boyf","boyg","boyo","boys","bozo","brad","brae","brag","brak","bran","bras","brat","braw","bray","bred","bree","brei","bren","brer","brew","brey","brie","brig","brik","brim","brin","brio","bris","brit","brod","brog","broo","bros","brow","brrr","brus","brut","brux","buat","buba","bubo","bubs","bubu","buck","buda","budi","budo","buds","buff","bufo","bugs","buhl","buhr","buik","buke","bulb","bulk","bull","bumf","bump","bums","buna","bund","bung","bunk","bunn","buns","bunt","buoy","bura","burb","burd","burg","burk","burl","burn","burp","burr","burs","bury","bush","busk","buss","bust","busy","bute","buts","butt","buys","buzz","byde","byes","byke","byre","byrl","byte"},
        {"caas","caba","cabs","caca","cade","cadi","cads","cafe","caff","cage","cags","cagy","caid","cain","cake","caky","calf","calk","call","calm","calo","calp","calx","cama","came","camo","camp","cams","cane","cang","cann","cans","cant","cany","capa","cape","caph","capi","capo","caps","carb","card","care","cark","carl","carn","carp","carr","cars","cart","casa","case","cash","cask","cast","cate","cats","cauf","cauk","caul","caum","caup","cava","cave","cavy","cawk","caws","cays","ceas","ceca","cede","cedi","cees","ceil","cell","cels","celt","cens","cent","cepe","ceps","cere","cero","cert","cess","cete","chad","chai","chal","cham","chao","chap","char","chas","chat","chav","chaw","chay","chef","cher","chew","chez","chia","chib","chic","chid","chik","chin","chip","chis","chit","chiv","chiz","choc","chog","chon","chop","chou","chow","chub","chug","chum","chut","ciao","cide","cids","ciel","cigs","cill","cine","cion","cire","cirl","cist","cite","cito","cits","city","cive","clad","clag","clam","clan","clap","clat","claw","clay","clef","cleg","clem","clew","clip","clod","clog","clon","clop","clot","clou","clow","cloy","club","clue","coal","coat","coax","cobb","cobs","coca","coch","cock","coco","coda","code","cods","coed","coff","coft","cogs","coho","coif","coil","coin","coir","coit","coke","coky","cola","cold","cole","coll","cols","colt","coly","coma","comb","come","comm","comp","coms","cond","cone","conf","coni","conk","conn","cons","cony","coof","cook","cool","coom","coon","coop","coos","coot","cope","cops","copy","cord","core","corf","cork","page 3","corm","corn","cors","cory","cose","cosh","coss","cost","cosy","cote","coth","cots","cott","coup","cour","cove","cowk","cowl","cowp","cows","cowy","coxa","coxy","coys","coze","cozy","crab","crag","cram","cran","crap","craw","cray","cred","cree","crem","crew","crib","crim","cris","crit","croc","crog","crop","crow","crud","crue","crus","crux","cube","cubs","cuds","cued","cues","cuff","cuif","cuit","cuke","cull","culm","cult","cunt","cups","curb","curd","cure","curf","curl","curn","curr","curs","curt","cush","cusk","cusp","cuss","cute","cuts","cwms","cyan","cyma","cyme","cyst","cyte","czar"},
        {"dabs","dace","dack","dada","dado","dads","daes","daff","daft","dago","dags","dahl","dahs","dais","daks","dale","dali","dals","dalt","dame","damn","damp","dams","dang","dank","dans","dant","daps","darb","dare","darg","dari","dark","darn","dart","dash","data","date","dato","daub","daud","daur","daut","davy","dawd","dawk","dawn","daws","dawt","days","daze","dead","deaf","deal","dean","dear","deaw","debe","debs","debt","deck","deco","deed","deek","deem","deen","deep","deer","dees","deet","deev","defi","deft","defy","degs","deid","deif","deil","deke","dele","delf","deli","dell","delo","dels","delt","deme","demo","demy","dene","deni","dens","dent","deny","dere","derm","dern","dero","derv","desi","desk","deus","deva","devs","dews","dewy","dexy","deys","dhak","dhal","dhol","dhow","dial","dibs","dice","dich","dick","dict","dido","didy","dieb","died","diel","dies","diet","diff","difs","digs","dika","dike","dill","dime","dimp","dims","dine","ding","dink","dino","dins","dint","diol","dips","dipt","dire","dirk","dirl","dirt","disa","disc","dish","disk","diss","dita","dite","dits","ditt","ditz","diva","dive","divi","divs","dixi","dixy","djin","doab","doat","dobs","doby","dock","doco","docs","dodo","dods","doek","doen","doer","does","doff","doge","dogs","dogy","dohs","doit","dojo","dole","doll","dols","dolt","dome","doms","domy","dona","done","dong","dons","doob","dook","dool","doom","doon","door","doos","dopa","dope","dops","dopy","dorb","dore","dork","dorm","dorp","dorr","dors","dort","dory","dose","dosh","doss","dost","dote","doth","dots","doty","douc","douk","doum","doun","doup","dour","dout","doux","dove","dowd","dowf","dowl","down","dowp","dows","dowt","doxy","doys","doze","dozy","drab","drac","drad","drag","dram","drap","drat","draw","dray","dree","dreg","drek","drew","drey","drib","drip","drop","drow","drub","drug","drum","drys","dsos","duad","dual","duan","duar","dubs","duce","duci","duck","duct","dude","duds","dued","duel","dues","duet","duff","dugs","duit","duka","duke","dule","dull","duly","duma","dumb","dump","dune","dung","dunk","duns","dunt","duos","dupe","dups","dura","dure","durn","duro","durr","dush","dusk","dust","duty","dwam","dyad","dyed","dyer","dyes","dyke","dyne","dzho","dzos"},
        {"each","eale","eans","eard","earl","earn","ears","ease","east","easy","eath","eats","eaus","eaux","eave","ebbs","ebon","ecad","ecce","ecco","eche","echo","echt","ecod","ecos","ecru","ecus","eddo","eddy","edge","edgy","edhs","edit","eech","eels","eely","eery","eevn","effs","efts","egad","egal","eger","eggs","eggy","egis","egma","egos","ehed","eide","eiks","eild","eina","eine","eish","eked","ekes","ekka","elan","elds","elfs","elhi","elks","ells","elms","elmy","else","elts","emes","emeu","emic","emir","emit","emma","emmy","emos","empt","emus","emyd","emys","ends","enes","enew","engs","enol","enow","enuf","envy","eoan","eons","eorl","epee","epha","epic","epos","eras","ered","eres","erev","ergo","ergs","eric","erks","erne","erns","eros","errs","erst","eruv","eses","esky","esne","espy","esse","ests","etas","etat","etch","eten","ethe","eths","etic","etna","etui","euge","eugh","euks","euoi","euro","even","ever","eves","evet","evil","evoe","evos","ewer","ewes","ewks","ewts","exam","exec","exed","exes","exit","exon","expo","exul","eyas","eyed","eyen","eyer","eyes","eyne","eyot","eyra","eyre","eyry"},
        {"faan","faas","fabs","face","fact","fade","fado","fads","fady","faff","fags","fahs","faik","fail","fain","fair","faix","fake","fall","falx","fame","fand","fane","fang","fank","fano","fans","fard","fare","farl","farm","faro","fars","fart","fash","fast","fate","fats","faun","faur","faut","faux","fava","fave","fawn","faws","fays","faze","feal","fear","feat","feck","feds","feeb","feed","feel","feen","feer","fees","feet","fegs","fehm","fehs","feis","fell","felt","feme","fems","fend","feni","fens","fent","feod","fere","ferm","fern","fess","fest","feta","fete","fets","fett","feud","feus","feys","fiar","fiat","fibs","fice","fico","fido","fids","fief","fier","fife","fifi","figo","figs","fike","fiky","fila","file","fill","film","filo","fils","find","fine","fini","fink","fino","fins","fire","firk","firm","firn","firs","fisc","fish","fisk","fist","fits","fitt","five","fixt","fizz","flab","flag","flak","flam","flan","flap","flat","flaw","flax","flay","flea","fled","flee","fleg","flew","flex","fley","flic","flim","flip","flir","flit","flix","floc","floe","flog","flop","flor","flow","flub","flue","flus","flux","foal","foam","fobs","foci","foen","foes","fogs","fogy","fohn","fohs","foid","foil","foin","fold","folk","fond","fone","fons","font","food","fool","foot","fops","fora","forb","ford","fore","fork","form","fort","foss","foud","foul","four","fous","fowl","foxy","foys","fozy","frab","frae","frag","frap","fras","frat","frau","fray","free","fret","frib","frig","fris","frit","friz","froe","frog","from","fros","frow","frug","fubs","fuci","fuck","fuds","fuel","fuff","fugs","fugu","fuji","full","fume","fums","fumy","fund","fung","funk","funs","furl","furr","furs","fury","fusc","fuse","fuss","fust","futz","fuze","fuzz","fyce","fyke","fyle","fyrd"},
        {"gabs","gaby","gade","gadi","gads","gaed","gaen","gaes","gaff","gaga","gage","gags","gaid","gain","gair","gait","gajo","gala","gale","gall","gals","gama","gamb","game","gamp","gams","gamy","gane","gang","gans","gant","gaol","gape","gapo","gaps","gapy","garb","gare","gari","gars","gart","gash","gasp","gast","gate","gath","gats","gaud","gaum","gaun","gaup","gaur","gaus","gave","gawd","gawk","gawp","gays","gaze","gazy","geal","gean","gear","geat","geck","geds","geed","geek","geep","gees","geez","geit","geld","gels","gelt","gems","gena","gene","gens","gent","genu","geos","gere","germ","gert","gest","geta","gets","geum","ghat","ghee","ghis","gibe","gibs","gids","gied","gien","gies","gift","giga","gigs","gila","gild","gill","gilt","gimp","ging","gink","ginn","gins","gios","gips","gird","girl","girn","giro","girr","girt","gism","gist","gite","gits","give","gizz","gjus","glad","glam","gled","glee","gleg","glei","glen","gley","glia","glib","glid","glim","glit","glob","glom","glop","glow","glue","glug","glum","glut","gnar","gnat","gnaw","gnow","gnus","goad","goaf","goal","goas","goat","gobo","gobs","goby","gods","goel","goer","goes","goey","goff","gogo","gold","gole","golf","golp","gone","gong","gonk","gons","good","goof","goog","gook","gool","goon","goop","goor","goos","gora","gore","gori","gorm","gorp","gory","gosh","goss","goth","gouk","gout","govs","gowd","gowf","gowk","gowl","gown","goys","grab","grad","gram","gran","grat","grav","gray","gree","gren","grew","grex","grey","grid","grig","grim","grin","grip","gris","grit","grog","grok","grot","grow","grub","grue","grum","guan","guar","gubs","guck","gude","gues","guff","guga","guid","gula","gule","gulf","gull","gulp","guls","guly","gump","gums","gung","gunk","guns","gups","gurl","gurn","gurs","guru","gush","gust","guts","guvs","guys","gyal","gybe","gymp","gyms","gyny","gyps","gyre","gyri","gyro","gyte","gyve"},
        {"haaf","haar","habu","hack","hade","hadj","hads","haed","haem","haen","haes","haet","haff","haft","hagg","hags","haha","hahs","haik","hail","hain","hair","haji","hajj","haka","hake","haku","hale","half","hall","halm","halo","halt","hame","hams","hand","hang","hank","hant","haps","hapu","hard","hare","hark","harl","harm","harn","haro","harp","hart","hash","hask","hasp","hast","hate","hath","hats","haud","hauf","haul","haut","have","hawk","hawm","haws","hays","haze","hazy","head","heal","heap","hear","heat","hebe","hech","heck","heed","heel","heft","hehs","heid","heil","heir","held","hele","hell","helm","helo","help","heme","hemp","hems","hend","hens","hent","heps","hept","herb","herd","here","herl","herm","hern","hero","hers","hery","hesp","hest","hete","heth","hets","hewn","hews","heys","hick","hide","hied","hies","high","hike","hila","hild","hili","hill","hilt","hims","hind","hing","hins","hint","hioi","hips","hipt","hire","hish","hisn","hiss","hist","hits","hive","hiya","hizz","hoar","hoas","hoax","hobo","hobs","hock","hods","hoed","hoer","hoes","hogg","hogh","hogs","hoha","hohs","hoik","hoka","hoke","hoki","hold","hole","holk","holm","holp","hols","holt","holy","homa","home","homo","homs","homy","hond","hone","hong","honk","hons","hood","hoof","hook","hoon","hoop","hoot","hope","hops","hora","hore","hori","horn","hors","hose","hoss","host","hote","hots","houf","hour","hout","hove","howe","howf","howk","howl","hows","hoya","hoys","hubs","huck","hued","huer","hues","huff","huge","hugs","hugy","huhu","huia","huic","huis","hula","hule","hulk","hull","huma","humf","hump","hums","hung","hunh","hunk","huns","hunt","hups","hurl","hurt","hush","husk","huso","huss","huts","hwan","hwyl","hyed","hyen","hyes","hyke","hyla","hyle","hymn","hype","hypo","hyps","hyte"}, 
        {"iamb","ibex","ibis","iced","icer","ices","ichs","icky","icon","idea","idee","idem","ides","idle","idly","idol","idyl","iffy","igad","iggs","iglu","ikan","ikat","ikon","ilea","ilex","ilia","ilka","ilks","ills","illy","imam","imid","immy","impi","imps","inby","inch","info","ingo","inia","inks","inky","inly","inns","inro","inti","into","ions","iota","ired","ires","irid","iris","irks","iron","isba","isit","isle","isms","isna","isos","itas","itch","item","iure","iwis","ixia","izar"},
        {"jaap","jabs","jack","jade","jafa","jaga","jagg","jags","jail","jake","jaks","jamb","jams","jane","jann","jape","japs","jark","jarl","jarp","jars","jasp","jass","jasy","jato","jauk","jaup","java","jaws","jaxy","jays","jazy","jazz","jean","jeat","jedi","jeed","jeel","jeep","jeer","jees","jeez","jefe","jeff","jehu","jell","jeon","jerk","jess","jest","jete","jets","jeux","jews","jiao","jibb","jibe","jibs","jiff","jigs","jill","jilt","jimp","jink","jinn","jins","jinx","jird","jism","jive","jivy","jizz","jobe","jobs","jock","joco","joes","joey","jogs","john","join","joke","joky","jole","joll","jols","jolt","jomo","jong","jook","jors","josh","joss","jota","jots","jouk","jour","jowl","jows","joys","juba","jube","juco","judo","juds","judy","juga","jugs","juju","juke","juku","jump","junk","jupe","jura","jure","jury","just","jute","juts","juve","jynx"},
        {"kaal","kaas","kabs","kade","kadi","kaed","kaes","kafs","kago","kagu","kaid","kaie","kaif","kaik","kail","kaim","kain","kais","kaka","kaki","kaks","kale","kali","kama","kame","kami","kana","kane","kang","kans","kant","kaon","kapa","kaph","kara","kark","karn","karo","kart","kata","kati","kats","kava","kawa","kaws","kayo","kays","kazi","kbar","keas","kebs","keck","keds","keef","keek","keel","keen","keep","keet","kefs","kegs","keir","keks","kell","kelp","kelt","kemb","kemp","keno","kens","kent","kepi","keps","kept","kerb","kerf","kern","kero","kesh","kest","keta","kete","keto","kets","kewl","keys","khaf","khan","khat","khet","khis","khor","khud","kibe","kick","kids","kief","kier","kiff","kifs","kike","kild","kill","kiln","kilo","kilp","kilt","kina","kind","kine","king","kink","kino","kins","kipe","kipp","kips","kirk","kirn","kirs","kish","kiss","kist","kite","kith","kits","kiva","kiwi","klap","klik","knag","knap","knar","knee","knew","knit","knob","knop","knot","know","knub","knur","knut","koan","koap","koas","kobo","kobs","koel","koff","koha","kohl","kois","koji","kola","kolo","kond","konk","kons","kook","koph","kops","kora","kore","koro","kors","koru","koss","koto","kows","krab","kris","ksar","kudo","kudu","kueh","kues","kufi","kuia","kuku","kula","kuna","kune","kuri","kuru","kuta","kuti","kutu","kuzu","kvas","kyak","kyar","kyat","kybo","kyes","kyle","kynd","kyne","kype","kyte","kyus"},
        {"lace","labs","lack","lacs","lacy","lade","lads","lady","laer","lags","lahs","laic","laid","laik","lain","lair","lake","lakh","laky","lall","lama","lamb","lame","lamp","lams","lana","land","lane","lang","lank","lant","lanx","laps","lard","lare","lari","lark","larn","lars","lase","lash","lass","last","late","lath","lati","lats","latu","laud","lauf","lava","lave","lavs","lawk","lawn","laws","lays","laze","lazo","lazy","lead","leaf","leak","leal","leam","lean","leap","lear","leas","leat","lech","leed","leek","leep","leer","lees","leet","left","legs","lehr","leir","leis","leke","leks","leku","leme","lend","leng","leno","lens","lent","leps","lept","lere","lerp","less","lest","lets","leud","leva","leve","levo","levy","lewd","leys","lezz","liar","lias","libs","lice","lich","lick","lido","lids","lied","lief","lien","lier","lies","lieu","life","lift","ligs","like","lill","lilo","lilt","lily","lima","limb","lime","limn","limo","limp","limy","lind","line","ling","link","linn","lino","lins","lint","liny","lion","lipa","lipe","lipo","lips","lira","lire","liri","lirk","lisk","lisp","list","lite","lith","lits","litu","live","load","loaf","loam","loan","lobe","lobi","lobo","lobs","loca","loch","loci","lock","loco","lode","lods","loft","loge","logo","logs","logy","loid","loin","loir","loke","loll","loma","lome","lone","long","loof","look","loom","loon","loop","loor","loos","loot","lope","lops","lord","lore","lorn","lory","lose","losh","loss","lost","lota","lote","loth","loti","loto","lots","loud","loun","loup","lour","lous","lout","love","lowe","lown","lowp","lows","lowt","loys","luau","lube","luce","luck","lude","ludo","luds","lues","luff","luge","lugs","luit","luke","lull","lulu","luma","lump","lums","luna","lune","lung","lunk","lunt","luny","lure","lurk","lurs","lush","lusk","lust","lute","lutz","luvs","luxe","lwei","lyam","lych","lyes","lyme","lyms","lyne","lynx","lyra","lyre","lyse","lyte"},
        {"maar","maas","mabe","mace","mach","mack","macs","made","mads","maes","mage","magg","magi","mags","maid","maik","mail","maim","main","mair","make","maki","mako","maks","mala","male","mali","mall","malm","mals","malt","mama","mams","mana","mand","mane","mang","mani","mano","mans","many","maps","mara","marc","mard","mare","marg","mark","marl","marm","mars","mart","mary","masa","mase","mash","mask","mass","mast","masu","mate","math","mats","matt","maty","maud","maul","maun","maut","mawk","mawn","mawr","maws","maxi","maya","mayo","mays","maze","mazy","mead","meal","mean","meat","meck","meds","meed","meek","meer","mees","meet","meff","mega","megs","mein","mela","meld","mell","mels","melt","meme","memo","mems","mend","mene","meng","meno","ment","menu","meou","meow","merc","mere","meri","merk","merl","mesa","mese","mesh","mess","meta","mete","meth","mets","meus","meve","mewl","mews","meze","mezz","mhos","mibs","mica","mice","mich","mick","mico","mics","midi","mids","mien","miff","migg","migs","miha","mihi","mike","mild","mile","milk","mill","milo","mils","milt","mime","mina","mind","mine","ming","mini","mink","mino","mint","minx","miny","mips","mire","miri","mirk","miro","mirs","mirv","miry","mise","miso","miss","mist","mite","mitt","mity","mixt","mixy","mizz","mnas","moai","moan","moas","moat","mobe","mobs","moby","moch","mock","mocs","mode","modi","mods","moer","moes","mofo","mogs","mohr","moil","moit","mojo","moke","moki","moko","mola","mold","mole","moll","mols","molt","moly","mome","momi","moms","mona","mong","monk","mono","mons","mony","mood","mooi","mook","mool","moon","moop","moor","moos","moot","mope","mops","mopy","mora","more","morn","mors","mort","mose","mosh","mosk","moss","most","mote","moth","moti","mots","mott","motu","moue","moup","mous","move","mowa","mown","mows","moxa","moya","moyl","moys","moze","mozo","mozz","much","muck","muds","muff","mugg","mugs","muid","muil","muir","mule","mull","mumm","mump","mums","mumu","mung","muni","muns","munt","muon","mura","mure","murk","murl","murr","muse","mush","musk","muso","muss","must","mute","muti","muts","mutt","muzz","myal","mycs","myna","myth","myxo","mzee"},
        {"naam","naan","nabe","nabk","nabs","nach","nada","nads","naff","naga","nags","naif","naik","nail","nain","nala","name","nams","namu","nana","nane","nans","naoi","naos","napa","nape","naps","narc","nard","nare","nark","nary","nats","nave","navy","nays","naze","nazi","neal","neap","near","neat","nebs","neck","neds","need","neem","neep","nefs","negs","neif","neks","nema","nemn","nene","neon","neps","nerd","nerk","nesh","ness","nest","nete","nets","nett","neuk","neum","neve","nevi","news","newt","next","nibs","nice","nick","nide","nidi","nids","nied","nief","nies","nife","niff","nigh","nill","nils","nimb","nims","nine","nipa","nips","nirl","nish","nisi","nite","nits","nixe","nixy","noah","nobs","nock","node","nodi","nods","noel","noes","nogg","nogs","noil","noir","nole","noll","nolo","noma","nome","noms","nona","none","nong","noni","nook","noon","noop","nope","nori","nork","norm","nose","nosh","nosy","nota","note","nott","noul","noun","noup","nous","nout","nova","nowl","nown","nows","nowt","nowy","noys","nubs","nude","nuff","nuke","null","numb","nuns","nurd","nurl","nurr","nurs","nuts","nyas","nyed","nyes"}, 
        {"oafs","oaks","oaky","oars","oary","oast","oath","oats","obas","obes","obey","obia","obis","obit","oboe","obol","obos","ocas","occy","oche","octa","odah","odal","odas","odds","odea","odes","odic","odor","odso","odyl","ofay","offs","ogam","ogee","ogle","ogre","ohed","ohia","ohms","ohos","oiks","oils","oily","oink","oint","okas","okay","okeh","okes","okra","okta","olds","oldy","olea","oleo","oles","olid","olio","olla","olms","olpe","ombu","omen","omer","omit","omov","once","oner","ones","onie","only","onos","onst","onto","onus","onyx","oofs","oofy","oohs","ooms","oons","oont","oops","oose","oosy","oots","ooze","oozy","opah","opal","oped","open","opes","oppo","opts","opus","orad","oral","orbs","orby","orca","orcs","ordo","ords","ores","orfe","orfs","orgy","orle","orra","orts","oryx","orzo","osar","oses","ossa","otic","otto","ouch","ouds","ouks","ould","oulk","ouma","oupa","ouph","oups","ourn","ours","oust","outs","ouzo","oval","ovel","oven","over","ovum","owed","ower","owes","owls","owly","owns","owre","owse","owts","oxen","oxer","oxes","oxid","oxim","oyer","oyes","oyez"},
        {"paal","paca","pace","pack","paco","pacs","pact","pacy","padi","pads","page","pahs","paid","paik","pail","pain","pair","pais","pale","pall","palm","palp","pals","paly","pams","pand","pane","pang","pans","pant","papa","pape","paps","para","pard","pare","park","parp","parr","pars","part","pase","pash","pass","past","pate","path","pats","patu","paty","paua","paul","pave","pavs","pawa","pawk","pawl","pawn","paws","pays","peag","peak","peal","pean","pear","peas","peat","peba","pech","peck","pecs","peds","peed","peek","peel","peen","peep","peer","pees","pegh","pegs","pehs","pein","peke","pela","pele","pelf","pell","pelt","pend","pene","peni","penk","pens","pent","peon","pepo","peps","pere","peri","perk","perm","pern","perp","pert","perv","peso","pest","pets","pews","pfft","pfui","phat","phew","phis","phiz","phoh","phon","phos","phot","phut","pial","pian","pias","pica","pice","pick","pics","pied","pier","pies","piet","pigs","pika","pike","piki","pila","pile","pili","pill","pily","pima","pimp","pina","pine","ping","pink","pins","pint","piny","pion","pioy","pipa","pipe","pipi","pips","pipy","pirl","pirn","pirs","pise","pish","piso","piss","pita","pith","pits","pity","pium","pixy","pize","plan","plap","plat","play","plea","pleb","pled","plew","plex","plie","plim","plod","plop","plot","plow","ploy","plue","plug","plum","plus","poas","pock","poco","pods","poem","poep","poet","pogo","pogy","pois","poke","poky","pole","polk","poll","polo","pols","polt","poly","pome","pomo","pomp","poms","pond","pone","pong","ponk","pons","pont","pony","pood","poof","pooh","pook","pool","poon","poop","poor","poos","poot","pope","pops","pore","pork","porn","port","pory","pose","posh","poss","post","posy","pote","pots","pott","pouf","pouk","pour","pout","pown","pows","poxy","pozz","prad","pram","prao","prat","prau","pray","pree","prem","prep","prex","prey","prez","prig","prim","proa","prob","prod","prof","prog","prom","proo","prop","pros","prow","pruh","prys","psis","psst","ptui","pube","pubs","puce","puck","puds","pudu","puer","puff","pugh","pugs","puha","puir","puja","puka","puke","puku","pula","pule","puli","pulk","pull","pulp","puls","pulu","puly","puma","pump","pumy","puna","pung","punk","puns","punt","puny","pupa","pups","pupu","pure","puri","purl","purr","purs","push","puss","puts","putt","putz","puys","pyas","pyat","pyes","pyet","pyic","pyin","pyne","pyot","pyre","pyro"},
        {"qadi","qaid","qats","qoph","quad","quag","quai","quat","quay","quep","quey","quid","quim","quin","quip","quit","quiz","quod","quop"},
        {"rabi","raca","race","rach","rack","racy","rade","rads","raff","raft","raga","rage","ragg","ragi","rags","rahs","raia","raid","raik","rail","rain","rais","rait","raja","rake","raki","raku","rale","rami","ramp","rams","rana","rand","rang","rani","rank","rant","rape","raps","rapt","rare","rark","rase","rash","rasp","rast","rata","rate","rath","rato","rats","ratu","raun","rave","rawn","raws","raya","rays","raze","razz","read","reak","real","ream","rean","reap","rear","rebs","reck","recs","redd","rede","redo","reds","reed","reef","reek","reel","reen","rees","refs","reft","rego","regs","rehs","reif","reik","rein","reis","reke","rely","rems","rend","renk","rens","rent","reny","reos","repo","repp","reps","resh","rest","rete","rets","revs","rews","rhea","rhos","rhus","rial","rias","riba","ribs","rice","rich","rick","ricy","ride","rids","riel","riem","rife","riff","rifs","rift","rigg","rigs","rile","rill","rima","rime","rims","rimu","rimy","rind","rine","ring","rink","rins","riot","ripe","ripp","rips","ript","rise","risk","risp","rite","rits","ritt","ritz","riva","rive","rivo","riza","road","roam","roan","roar","robe","robs","roch","rock","rocs","rode","rods","roed","roes","roil","roin","roji","roke","roks","roky","role","rolf","roll","roma","romp","roms","rone","rong","ront","rood","roof","rook","room","roon","roop","roos","root","rope","ropy","rore","rort","rory","rose","rost","rosy","rota","rote","roti","rotl","roto","rots","roue","roul","roum","roup","rout","roux","rove","rows","rowt","rube","rubs","ruby","ruck","rucs","rudd","rude","ruds","rued","ruer","rues","ruff","ruga","rugs","ruin","rukh","rule","ruly","rume","rump","rums","rund","rune","rung","runs","runt","rurp","ruru","rusa","ruse","rush","rusk","rust","ruth","ruts","ryal","ryas","ryes","ryfe","ryke","rynd","ryot","rype"},
        {"sabe","sabs","sack","sacs","sade","sadi","sado","sads","safe","saft","saga","sage","sago","sags","sagy","saic","said","sail","saim","sain","sair","sais","sake","saki","sale","sall","salp","sals","salt","sama","same","samp","sams","sand","sane","sang","sank","sans","sant","saps","sard","sari","sark","sars","sash","sass","sate","sati","saul","saut","save","savs","sawn","saws","saxe","says","scab","scad","scag","scam","scan","scar","scat","scaw","scog","scop","scot","scow","scry","scud","scug","scul","scum","scup","scur","scut","scye","seal","seam","sean","sear","seas","seat","sech","seco","secs","sect","seed","seek","seel","seem","seen","seep","seer","sees","sego","segs","seif","seik","seil","seir","seis","sekt","seld","sele","self","sell","sels","seme","semi","sena","send","sene","sens","sent","seps","sept","sera","sere","serf","serk","serr","sers","sese","sesh","sess","seta","sets","sett","sewn","sews","sext","sexy","seys","shad","shag","shah","sham","shan","shat","shaw","shay","shea","shed","shes","shet","shew","shim","shin","ship","shir","shit","shiv","shmo","shod","shoe","shog","shoo","shop","shot","show","shri","shul","shun","shut","shwa","sial","sibb","sibs","sice","sich","sick","sics","sida","side","sidh","sien","sies","sift","sigh","sign","sijo","sika","sike","sild","sile","silk","sill","silo","silt","sima","simi","simp","sims","sind","sine","sing","sinh","sink","sins","sipe","sips","sire","siri","sirs","siss","sist","site","sith","sits","sitz","size","sizy","sjoe","skag","skas","skat","skaw","skee","skeg","sken","skeo","skep","sker","sket","skew","skid","skim","skin","skio","skip","skis","skit","skol","skry","skua","skug","skyf","skyr","slab","slae","slag","slam","slap","slat","slaw","slay","sled","slee","slew","sley","slid","slim","slip","slit","slob","sloe","slog","slop","slot","slow","slub","slue","slug","slum","slur","slut","smee","smew","smir","smit","smog","smug","smur","smut","snab","snag","snap","snar","snaw","sneb","sned","snee","snib","snig","snip","snit","snob","snod","snog","snot","snow","snub","snug","snye","soak","soap","soar","soba","sobs","soca","sock","socs","soda","sods","sofa","soft","sogs","soho","sohs","soil","soja","soke","sola","sold","sole","soli","solo","sols","soma","some","soms","somy","sone","song","sons","sook","sool","soom","soon","soop","soot","soph","sops","sora","sorb","sord","sore","sori","sorn","sort","soss","soth","sots","souk","soul","soum","soup","sour","sous","sout","sovs","sowf","sowl","sowm","sown","sowp","sows","soya","soys","spae","spag","spam","span","spar","spas","spat","spaw","spay","spaz","spec","sped","spek","spet","spew","spic","spie","spif","spik","spim","spin","spit","spiv","spod","spot","spry","spud","spue","spug","spun","spur","sris","stab","stag","stap","star","stat","staw","stay","sted","stem","sten","step","stet","stew","stey","stie","stim","stir","stoa","stob","stop","stot","stow","stub","stud","stum","stun","stye","suba","subs","such","suck","sudd","suds","sued","suer","sues","suet","sugh","suid","suit","sukh","suks","sulk","sulu","sumo","sump","sums","sumy","sung","sunk","sunn","suns","supe","sups","suqs","sura","surd","sure","surf","suss","susu","swab","swad","swag","swam","swan","swap","swat","sway","swee","swey","swig","swim","swiz","swob","swop","swot","swum","sybo","syce","syed","syen","syes","syke","syli","sync","synd","syne","sype","syph"},
        {"taal","tabi","tabs","tabu","tace","tach","tack","taco","tact","tads","taed","tael","taes","tags","taha","tahr","taig","tail","tain","tais","tait","taka","take","taki","taks","taky","tala","talc","tale","tali","talk","tall","tame","tamp","tams","tana","tane","tang","tanh","tank","tans","taos","tapa","tape","taps","tapu","tara","tare","tarn","taro","tarp","tars","tart","tash","task","tass","tate","tath","tats","tatt","tatu","taus","taut","tava","tavs","tawa","taws","tawt","taxa","taxi","tays","tead","teak","teal","team","tear","teas","teat","tech","tecs","teds","tedy","teed","teek","teel","teem","teen","teer","tees","teff","tefs","tegg","tegs","tegu","tehr","teil","tela","teld","tele","tell","tels","telt","teme","temp","tems","tend","tene","tens","tent","tepa","terf","term","tern","test","tete","teth","tets","tews","text","thae","than","thar","that","thaw","thee","them","then","thew","they","thig","thin","thio","thir","this","thon","thou","thro","thru","thud","thug","thus","tiar","tice","tich","tick","tics","tide","tids","tidy","tied","tier","ties","tiff","tift","tige","tigs","tika","tike","tiki","tile","till","tils","tilt","time","tind","tine","ting","tink","tins","tint","tiny","tipi","tips","tipt","tire","tirl","tiro","tirr","tite","titi","tits","tivy","tizz","toad","toby","tock","toco","tocs","tods","tody","toea","toed","toes","toey","toff","toft","tofu","toga","toge","togs","toho","toil","toit","toke","toko","tola","told","tole","toll","tolt","tolu","tomb","tome","tomo","toms","tone","tong","tonk","tons","tony","took","tool","toom","toon","toot","tope","toph","topi","topo","tops","tora","torc","tore","tori","torn","toro","torr","tors","tort","tory","tosa","tose","tosh","toss","tost","tote","tots","touk","toun","tour","tout","town","tows","towt","towy","toyo","toys","toze","trad","tram","trap","trat","tray","tree","tref","trek","tres","tret","trew","trey","trez","trie","trig","trim","trin","trio","trip","trod","trog","tron","trop","trot","trow","troy","trug","trye","tryp","tsar","tsks","tuan","tuba","tube","tubs","tuck","tufa","tuff","tuft","tugs","tuis","tule","tump","tums","tuna","tund","tune","tung","tuns","tuny","tups","turd","turf","turk","turm","turn","tush","tusk","tuts","tutu","tuzz","twae","twal","twas","twat","tway","twee","twig","twin","twit","twos","tyde","tyed","tyee","tyer","tyes","tygs","tyin","tyke","tymp","tynd","tyne","type","typo","typp","typy","tyre","tyro","tyte","tzar"},
        {"udal","udon","udos","ueys","ufos","ughs","ugly","ukes","ulan","ules","ulex","ulna","ulus","ulva","umbo","umph","umps","umpy","unai","unau","unbe","unce","unci","unco","unde","undo","undy","unis","unit","unto","upas","upby","updo","upgo","upon","upsy","upta","urao","urbs","urde","urds","urdy","urea","ures","urge","uric","urns","urps","ursa","urus","urva","used","user","uses","utas","utes","utis","utus","uvae","uvas","uvea"},
        {"vacs","vade","vaes","vagi","vags","vail","vain","vair","vale","vali","vamp","vane","vang","vans","vant","vara","vare","vars","vary","vasa","vase","vast","vats","vatu","vaus","vaut","vavs","vaws","veal","veep","veer","vees","vega","vego","vehm","veil","vein","vela","veld","vele","vell","vena","vend","vent","vera","verb","verd","vers","vert","very","vest","veto","vets","vext","viae","vial","vias","vibe","vibs","vice","vide","vids","vied","vier","vies","view","viga","vigs","vild","vile","vill","vims","vina","vine","vino","vins","vint","viny","viol","vire","virl","visa","vise","vita","vite","viva","vive","vivo","vizy","vlei","voar","voes","void","vola","vole","volk","vols","volt","vors","vote","vows","vril","vrot","vrou","vrow","vugg","vugh","vugs","vuln","vums"},
        {"waac","wabs","wack","wadd","wade","wadi","wads","wadt","wady","waes","waff","waft","wage","wags","waid","waif","wail","wain","wair","wais","wait","waka","wake","wakf","wald","wale","wali","walk","wall","waly","wame","wand","wane","wang","wank","wans","want","wany","waps","waqf","warb","ward","ware","wark","warm","warn","warp","wars","wart","wary","wase","wash","wasm","wasp","wast","wate","wats","watt","wauk","waul","waur","wave","wavy","wawa","wawe","wawl","waws","waxy","ways","weak","weal","wean","wear","webs","weds","weed","week","weel","weem","ween","weep","weer","wees","weet","weft","weid","weil","weir","weka","weld","welk","well","welt","wemb","wems","wena","wend","wens","went","wept","were","wero","wert","west","weta","wets","wexe","weys","whae","wham","whap","what","whee","when","whet","whew","whey","whid","whig","whim","whin","whio","whip","whir","whit","whiz","whoa","whom","whop","whot","whow","whup","whys","wice","wich","wick","wide","wiel","wife","wigs","wild","wile","wili","will","wilt","wily","wimp","wind","wine","wing","wink","winn","wino","wins","winy","wipe","wire","wiry","wise","wish","wisp","wiss","wist","wite","with","wits","wive","woad","wock","woes","wofs","wogs","woke","woks","wold","wolf","womb","wonk","wons","wont","wood","woof","wool","woon","woos","woot","wops","word","wore","work","worm","worn","wort","wost","wots","wove","wowf","wows","wrap","wren","writ","wuds","wudu","wull","wuss","wych","wyes","wyle","wynd","wynn","wyns","wyte"},
        {"xyst"},
        {"yaar","yaba","yack","yads","yaff","yagi","yags","yahs","yaks","yald","yale","yams","yang","yank","yapp","yaps","yard","yare","yark","yarn","yarr","yate","yaud","yaup","yawl","yawn","yawp","yaws","yawy","yays","ybet","yead","yeah","yean","year","yeas","yebo","yech","yede","yeed","yegg","yeld","yelk","yell","yelm","yelp","yelt","yens","yeps","yerd","yerk","yesk","yest","yeti","yett","yeuk","yeve","yews","ygoe","yids","yike","yill","yins","yipe","yips","yird","yirk","yirr","yite","ylem","ylke","ympe","ympt","yobs","yock","yode","yodh","yods","yoga","yogh","yogi","yoke","yoks","yold","yolk","yomp","yond","yoni","yont","yoof","yoop","yore","york","yorp","youk","your","yous","yowe","yowl","yows","yuan","yuca","yuch","yuck","yuft","yuga","yugs","yuke","yuko","yuks","yuky","yule","yump","yunx","yups","yurt","yutz","yuzu","ywis"},
        {"zack","zags","zany","zaps","zarf","zati","zeal","zeas","zebu","zeds","zees","zein","zeks","zels","zeps","zerk","zero","zest","zeta","zeze","zhos","ziff","zigs","zila","zill","zimb","zinc","zine","zing","zins","zips","zite","ziti","zits","zizz","zobo","zobu","zoea","zoic","zols","zona","zone","zonk","zoom","zoon","zoos","zoot","zori","zouk","zulu","zupa","zurf","zyga","zyme","zzzs"},
    };
    int rvalue=0;
    int usrwrdlen;
    usrwrdlen=s1.length();
    if(usrwrdlen==4)
    {
        int nth_alpha;
        nth_alpha=(int)s1[0]-97;
        for(int i=0;i<500;i++)
        {  
            rvalue=issame(s1,validwords[nth_alpha][i]);
            if ( rvalue==1 )
            {
                rvalue=101;
                break;
            }
        }
        if ( rvalue==101 )
        {
            rvalue=isrepeat(s1);
        }
        if ( rvalue==0 )
        {
            rvalue=102;
        }
       
    }
    else if ( usrwrdlen<4 ) {
        rvalue=104;
    }
    else if ( usrwrdlen>4 ) {
        rvalue=105;
    }
    return rvalue;
}