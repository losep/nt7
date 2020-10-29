#include <ansi.h>

#define DB_D          "/adm/daemons/dbd"
#define DIALOG_D      "/adm/daemons/dialogd"
#define SUICONG_D     "/adm/daemons/suicongd"
#define SKYBOOK_D     "/adm/daemons/skybookd"
#define FUBEN_D       "/adm/daemons/fuben_daemonsd"

#define DEBOOKS "笑傲江湖"


inherit ITEM;

// 序章开始时调用的剧情简介
string *sBookMsg = ({
        "其时武林之中，既有正邪之判，复存门户之别，少林、武当、青城、五岳自诩正教与魔教（日月神教）冤冤相报，誓不两立。",
        "五岳剑派名虽一体，实存芥蒂。嵩山掌门左冷禅野心勃勃，意欲吞并五岳，称霸江湖，自恃盟主身份，凌驾四岳掌门，挑拨华山剑宗争夺掌门之位。",
        "岳不群原属气宗，剑、气二宗素不相和，不群率本门弟子外出避祸，遭左道之士埋伏，俱被擒获。",
        "江湖之中流传着一个传说，林家祖传的《辟邪剑法》乃天下无敌之武功，谁能练成将天下无敌！",
        "福建林远图以七十二路辟邪剑法称雄武林，创立福威镖局，笑傲江湖，驰骋天下。",
        "远图死后，子孙无能，四方豪杰觊觎辟邪剑谱，纷至沓来 ……",
        "辟邪剑谱之争，武林盟主之争，由此拉开序幕！",
});

mapping mSkybook_fuben = ([
        "任务编号数字"   :   "章节名:副本名:故事描述:linghuchong:令狐冲:气血1-气血2-气血3:攻击力1-攻击力2-攻击力3:防御力1-防御力2-防御力3:dugu-jiujian:等级1-等级2-等级3:兵器类型:5:BOSS性别", 
                                // 章节名:副本名:副本描述:BOSS文件名:BOSS中文名:三个难度的气血:三个难度的攻击:三个难度的防御:主要攻击技能:三个难度的技能等级:兵器类型:下一个任务编号:性别
                                // 兵器类型为sword, blade,pin等标准定义，也可填写strike, hand
"1":"第一章:路见不平:青城派弟子欺辱一个文弱公子，你路见不平，拔刀相助。:xajh1:青城派弟子:25000000-50000000-100000000:25000-50000-75000:25000-60000-100000:cuixin-zhang:500:strike:5:男性",
"5":"第一章:青城四少:青城派弟子带来了帮手，传说中的青城四少，看样子你不得不动武了。:xajh5:青城四少:27500000-55000000-110000000:27500-55000-82500:27500-66000-110000:cuixin-zhang:550:strike:10:男性",
"10":"第一章:变脸:原来你搭救的是福威镖局的少东家林平之，惹怒了青城派掌门人余沧海，据说他会变脸，不好对付。:xajh10:余沧海:30000000-60000000-120000000:30000-60000-90000:30000-72000-120000:cuixin-zhang:600:strike:15:男性",
"15":"第一章:灭门1:林家被灭门，仅林平之逃出，但是被青城派一路追杀。:xajh15:青城派堂主:32500000-65000000-130000000:32500-65000-97500:32500-78000-130000:cuixin-zhang:650:strike:20:男性",
"20":"第一章:灭门2:林家被灭门，仅林平之逃出，但是被青城派一路追杀。:xajh20:余人杰:35000000-70000000-140000000:35000-70000-105000:35000-84000-140000:cuixin-zhang:700:strike:25:男性",
"25":"第一章:灭门3:林家被灭门，仅林平之逃出，但是被青城派一路追杀。:xajh25:平沙落雁:37500000-75000000-150000000:37500-75000-112500:37500-90000-150000:cuixin-zhang:750:strike:30:男性",
"30":"第一章:误会1:救出林平之，被华山派弟子误会，打了起来。:xajh30:劳德诺:40000000-80000000-160000000:40000-80000-120000:40000-96000-160000:hunyuan-zhang:800:strike:35:男性",
"35":"第一章:误会2:听说其中一位叫令狐冲的是华山派大弟子，想和你切磋切磋。:xajh35:令狐冲:42500000-85000000-170000000:42500-85000-127500:42500-102000-170000:huashan-jian:850:sword:40:男性",
"40":"第一章:潇湘夜雨:一阵琴音飘来，一位老者似乎路见不平，向你发起挑战。:xajh40:莫大:45000000-90000000-180000000:45000-90000-135000:45000-108000-180000:shilin-jian:900:sword:45:男性",
"45":"第一章:采花大盗:听说衡阳刘正风金盆洗手打会甚是热闹，你在前往的路上遇到传说中的采花贼田伯光，一句不和跟他打了起来。:xajh45:田伯光:47500000-95000000-190000000:47500-95000-142500:47500-114000-190000:kuangfeng-blade:950:blade:50:男性",
"50":"第一章:塞北明驼:金盆洗手大会上，塞北明驼木高峰咄咄逼人，得教训教训他了。:xajh50:木高峰:50000000-100000000-200000000:50000-100000-150000:50000-120000-200000:luohan-quan:1000:cuff:55:男性",
"55":"第一章:沧海桑田:青城派余沧海显然对你不满至极，想在今日了结你们的恩怨。:xajh55:余沧海:52500000-105000000-210000000:52500-105000-157500:52500-126000-210000:cuixin-zhang:1050:strike:60:男性",
"60":"第二章:金盆洗手1:嵩山派费斌奉盟主左冷禅之命，阻挠刘正风金盆洗手。:xajh60:费斌:55000000-110000000-220000000:55000-110000-165000:55000-132000-220000:songyang-zhang:1100:strike:65:男性",
"65":"第二章:金盆洗手2:嵩山派丁勉奉盟主左冷禅之命，阻挠刘正风金盆洗手。:xajh65:丁勉:57500000-115000000-230000000:57500-115000-172500:57500-138000-230000:yinyang-zhang:1150:strike:70:男性",
"70":"第二章:金盆洗手3:嵩山派陆柏奉盟主左冷禅之命，阻挠刘正风金盆洗手。:xajh70:陆柏:60000000-120000000-240000000:60000-120000-180000:60000-144000-240000:yinyang-zhang:1200:strike:75:男性",
"75":"第二章:曲谱:刘正风和曲洋对你的相救之恩万分感激，将《笑傲江湖》曲谱赠送与你。无奈又遇到费斌赶来追杀，最终二人自刎以嘲笑天下。:xajh75:费斌:62500000-125000000-250000000:62500-125000-187500:62500-150000-250000:songyang-zhang:1250:strike:80:男性",
"80":"第二章:赠谱:你见《笑傲江湖》曲谱转送给令狐冲。路遇岳不群视你为魔教，向你发动攻势。:xajh80:岳不群:65000000-130000000-260000000:65000-130000-195000:65000-156000-260000:hunyuan-zhang:1300:strike:85:男性",
"85":"第二章:面壁:令狐冲被你牵连，岳不群罚他去华山后山面壁一年，你前往探望，路遇采花大盗田伯光……:xajh85:田伯光:67500000-135000000-270000000:67500-135000-202500:67500-162000-270000:kuangfeng-blade:1350:blade:90:男性",
"90":"第三章:神剑出窍:华山后山，遇风清扬指导武学，切磋一番。:xajh90:风清扬:73500000-147000000-294000000:73500-147000-220500:73500-176400-294000:dugu-jiujian:1470:sword:95:男性",
"95":"第三章:六个仙人:从华山下山后，遇到六个怪人，自称是仙，对你百般阻挠，无奈之下只能动武。:xajh95:桃谷六仙:79500000-159000000-318000000:79500-159000-238500:79500-190800-318000:taiji-quan:1590:unarmed:100:男性",
"100":"第三章:胖和尚:胖和尚误认为你是采花大盗，说什么都不让你离开华山。:xajh100:不戒和尚:85500000-171000000-342000000:85500-171000-256500:85500-205200-342000:xianglong-zhang:1710:strike:105:男性",
"105":"第三章:大战方生:前面之事误会太多，江湖中人都误认你为魔教党羽，少林派对你也不罢休。:xajh105:方生大师:91500000-183000000-366000000:91500-183000-274500:91500-219600-366000:qianye-shou:1830:hand:110:男性",
"110":"第三章:天王老子:出得少林，路遇众人追击魔教长老，你出手相助决定除掉魔教中人，以正名声。:xajh110:向问天:97500000-195000000-390000000:97500-195000-292500:97500-234000-390000:qingmang-zhang:1950:strike:115:男性",
"115":"第三章:不打不相识:原来此长老是魔教护法向问天，为人豪爽，众人以多欺少，反倒令你心生厌恶，决定助向问天脱险:xajh115:向问天仇家:103500000-207000000-414000000:103500-207000-310500:103500-248400-414000:chousui-zhang:2070:strike:120:男性",
"120":"第四章:独战群雄1:群雄见你帮向问天，决定先铲除你而后快。青城派侯人雄率先发难。:xajh120:侯人雄:109500000-219000000-438000000:109500-219000-328500:109500-262800-438000:cuixin-zhang:2190:strike:125:男性",
"125":"第四章:独战群雄2:原来向问天也得罪了魔教，魔教八雄齐上。:xajh125:魔教八雄:115500000-231000000-462000000:115500-231000-346500:115500-277200-462000:cuixin-zhang:2310:strike:130:男性",
"130":"第四章:独战群雄3:泰山派天乙道人出手，向你攻了过来。:xajh130:天乙道人:121500000-243000000-486000000:121500-243000-364500:121500-291600-486000:taiji-jian:2430:sword:135:男性",
"135":"第四章:独战群雄4:嵩山大阴阳手乐厚从背后偷袭你，小心！:xajh135:乐厚:127500000-255000000-510000000:127500-255000-382500:127500-306000-510000:yinyang-zhang:2550:strike:140:男性",
"140":"第四章:梅庄救人1:一轮恶战结束后，你答应跟向问天前往梅庄营救神秘人物。:xajh140:丹青生:133500000-267000000-534000000:133500-267000-400500:133500-320400-534000:jidian-jian:2670:sword:145:男性",
"145":"第四章:梅庄救人2:一轮恶战结束后，你答应跟向问天前往梅庄营救神秘人物。:xajh145:秃笔翁:139500000-279000000-558000000:139500-279000-418500:139500-334800-558000:pomopima-jian:2790:sword:150:男性",
"150":"第四章:梅庄救人3:一轮恶战结束后，你答应跟向问天前往梅庄营救神秘人物。:xajh150:黑白子:145500000-291000000-582000000:145500-291000-436500:145500-349200-582000:xuantian-zhi:2910:finger:155:男性",
"155":"第四章:梅庄救人4:一轮恶战结束后，你答应跟向问天前往梅庄营救神秘人物。:xajh155:黄钟公:151500000-303000000-606000000:151500-303000-454500:151500-363600-606000:qixian-wuxingjian:3030:sword:160:男性",
"160":"第四章:梅庄救人5:一轮恶战结束后，你答应跟向问天前往梅庄营救神秘人物。:xajh160:受伤的任我行:157500000-315000000-630000000:157500-315000-472500:157500-378000-630000:yuanshi-jian:3150:sword:165:男性",
"165":"第四章:梅庄救人6:东方不败派人来查，事情败露，不得不战。:xajh165:秦伟邦:163500000-327000000-654000000:163500-327000-490500:163500-392400-654000:zhenyu-quan:3270:cuff:170:男性",
"170":"第五章:日月神教1:与任我行，向问天及任盈盈前往日月神教诛杀东方不败。:xajh170:鲍大楚:169500000-339000000-678000000:169500-339000-508500:169500-406800-678000:zhenyu-quan:3390:cuff:175:男性",
"175":"第五章:日月神教2:与任我行，向问天及任盈盈前往日月神教诛杀东方不败。:xajh175:魔教长老:175500000-351000000-702000000:175500-351000-526500:175500-421200-702000:zhenyu-quan:3510:cuff:180:男性",
"180":"第五章:日月神教3:与任我行，向问天及任盈盈前往日月神教诛杀东方不败。:xajh180:魔教护法:181500000-363000000-726000000:181500-363000-544500:181500-435600-726000:zhenyu-quan:3630:cuff:185:男性",
"185":"第五章:日月神教4:与任我行，向问天及任盈盈前往日月神教诛杀东方不败。:xajh185:杨莲亭:187500000-375000000-750000000:187500-375000-562500:187500-450000-750000:qixian-wuxingjian:3750:sword:190:男性",
"190":"第五章:日月神教5:与任我行，向问天及任盈盈前往日月神教诛杀东方不败。:xajh190:东方不败:193500000-387000000-774000000:193500-387000-580500:193500-464400-774000:kuihua-mogong:3870:finger:195:无性",
"195":"第五章:营救圣姑1:任盈盈被少林寺软禁，前往营救。:xajh195:桃谷六仙:199500000-399000000-798000000:199500-399000-598500:199500-478800-798000:kongming-quan:3990:unarmed:200:男性",
"200":"第五章:营救圣姑2:任盈盈被少林寺软禁，前往营救。:xajh200:冲虚道长:205500000-411000000-822000000:205500-411000-616500:205500-493200-822000:taiji-quan:4110:unarmed:205:男性",
"205":"第五章:营救圣姑3:任盈盈被少林寺软禁，前往营救。:xajh205:方生大师:211500000-423000000-846000000:211500-423000-634500:211500-507600-846000:qianye-shou:4230:hand:210:男性",
"210":"第五章:营救圣姑4:任盈盈被少林寺软禁，前往营救。:xajh210:余沧海:217500000-435000000-870000000:217500-435000-652500:217500-522000-870000:cuixin-zhang:4350:strike:215:男性",
"215":"第五章:营救圣姑5:任盈盈被少林寺软禁，前往营救。:xajh215:左冷禅:223500000-447000000-894000000:223500-447000-670500:223500-536400-894000:hanbing-zhang:4470:strike:220:男性",
"220":"第五章:营救圣姑6:任盈盈被少林寺软禁，前往营救。:xajh220:方证大师:229500000-459000000-918000000:229500-459000-688500:229500-550800-918000:qianye-shou:4590:hand:225:男性",
"225":"第六章:华山大战1:协助令狐冲返回华山派，不料偶遇一场大战。:xajh225:封不平:235500000-471000000-942000000:235500-471000-706500:235500-565200-942000:huashan-jian:4710:sword:230:男性",
"230":"第六章:华山大战2:协助令狐冲返回华山派，不料偶遇一场大战。:xajh230:成不忧:241500000-483000000-966000000:241500-483000-724500:241500-579600-966000:huashan-jian:4830:sword:235:男性",
"235":"第六章:华山大战3:协助令狐冲返回华山派，不料偶遇一场大战。:xajh235:岳不群:247500000-495000000-990000000:247500-495000-742500:247500-594000-990000:hunyuan-zhang:4950:strike:240:男性",
"240":"第六章:华山大战4:协助令狐冲返回华山派，不料偶遇一场大战。:xajh240:大力神魔范松:253500000-507000000-1014000000:253500-507000-760500:253500-608400-1014000:zhenyu-quan:5070:cuff:245:男性",
"245":"第六章:华山大战5:协助令狐冲返回华山派，不料偶遇一场大战。:xajh245:金猴神魔张乘风:263500000-527000000-1054000000:263500-527000-790500:263500-632400-1054000:zhenyu-quan:5270:cuff:250:男性",
"250":"第六章:华山大战6:协助令狐冲返回华山派，不料偶遇一场大战。:xajh250:白猿神魔张乘云:273500000-547000000-1094000000:273500-547000-820500:273500-656400-1094000:zhenyu-quan:5470:cuff:255:男性",
"255":"第七章:五岳会战1:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh255:玉玑子:283500000-567000000-1134000000:283500-567000-850500:283500-680400-1134000:taishan-sword:5670:sword:260:男性",
"260":"第七章:五岳会战2:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh260:莫大:293500000-587000000-1174000000:293500-587000-880500:293500-704400-1174000:shilin-jian:5870:sword:265:男性",
"265":"第七章:五岳会战3:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh265:定闲师太:303500000-607000000-1214000000:303500-607000-910500:303500-728400-1214000:hengshan-jian:6070:sword:270:女性",
"270":"第七章:五岳会战4:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh270:岳不群:313500000-627000000-1254000000:313500-627000-940500:313500-752400-1254000:pixie-jian:6270:sword:275:男性",
"275":"第七章:五岳会战5:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh275:左冷禅:323500000-647000000-1294000000:323500-647000-970500:323500-776400-1294000:hanbing-zhang:6470:strike:280:男性",
"280":"第七章:五岳会战6:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh280:任盈盈:333500000-667000000-1334000000:333500-667000-1000500:333500-800400-1334000:lansha-shou:6670:hand:285:女性",
"285":"第七章:五岳会战7:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh285:令狐冲:343500000-687000000-1374000000:343500-687000-1030500:343500-824400-1374000:dugu-jiujian:6870:sword:290:男性",
"290":"第七章:五岳会战8:五岳派推举盟主，胜者为王。武林盟主你势在必得！:xajh290:方证大师:353500000-707000000-1414000000:353500-707000-1060500:353500-848400-1414000:qianye-shou:7070:hand:295:男性",
"295":"第八章:决战1:你拒绝加入日月神教，决战的时候到了。:xajh295:上官云:363500000-727000000-1454000000:363500-727000-1090500:363500-872400-1454000:qingmang-zhang:7270:strike:300:男性",
"300":"第八章:决战2:你拒绝加入日月神教，决战的时候到了。:xajh300:鲍大楚:373500000-747000000-1494000000:373500-747000-1120500:373500-896400-1494000:qingmang-zhang:7470:strike:305:男性",
"305":"第八章:决战3:你拒绝加入日月神教，决战的时候到了。:xajh305:童百熊:383500000-767000000-1534000000:383500-767000-1150500:383500-920400-1534000:qingmang-zhang:7670:strike:310:男性",
"310":"第八章:决战4:你拒绝加入日月神教，决战的时候到了。:xajh310:向问天:393500000-787000000-1574000000:393500-787000-1180500:393500-944400-1574000:qingmang-zhang:7870:strike:315:男性",
"315":"第八章:决战5:你拒绝加入日月神教，决战的时候到了。:xajh315:任盈盈:403500000-807000000-1614000000:403500-807000-1210500:403500-968400-1614000:lansha-shou:8070:hand:320:女性",
"320":"第八章:决战6:你拒绝加入日月神教，决战的时候到了。:xajh320:任我行:413500000-827000000-1654000000:413500-827000-1240500:413500-992400-1654000:yuanshi-jian:8270:sword:325:男性",
"325":"第九章:归隐1:你看淡江湖，决心归隐，不再笑傲江湖，最后的一战在所难免。:xajh325:左冷禅:423500000-847000000-1694000000:423500-847000-1270500:423500-1016400-1694000:hanbing-zhang:8470:strike:330:男性",
"330":"第九章:归隐2:你看淡江湖，决心归隐，不再笑傲江湖，最后的一战在所难免。:xajh330:桃谷六仙:433500000-867000000-1734000000:433500-867000-1300500:433500-1040400-1734000:taiji-quan:8670:unarmed:335:男性",
"335":"第九章:归隐3:你看淡江湖，决心归隐，不再笑傲江湖，最后的一战在所难免。:xajh335:岳不群:443500000-887000000-1774000000:443500-887000-1330500:443500-1064400-1774000:pixie-jian:8870:sword:340:无性",
"340":"第九章:归隐4:你看淡江湖，决心归隐，不再笑傲江湖，最后的一战在所难免。:xajh340:林平之:453500000-907000000-1814000000:453500-907000-1360500:453500-1088400-1814000:pixie-jian:9070:sword:345:无性",
"345":"第九章:归隐5:你看淡江湖，决心归隐，不再笑傲江湖，最后的一战在所难免。:xajh345:红叶禅师:463500000-927000000-1854000000:463500-927000-1390500:463500-1112400-1854000:pixie-jian:9270:sword:350:无性",
"350":"第九章:归隐6:你看淡江湖，决心归隐，不再笑傲江湖，最后的一战在所难免。:xajh350:令狐冲:500000000-1000000000-2000000000:500000-1000000-1500000:500000-1200000-2000000:dugu-jiujian:10000:sword:9999:男性",

 "9999"  : "大结局:0:0:0:0:0:0:0:0:0:0:0:0",
]);


public get_mSkybook_fuben(string sQuest, int flag)
{
                string *keys_info;
                
                keys_info = explode(mSkybook_fuben[sQuest], ":");
                
                return keys_info[flag];
}

// 获取副本的最快记录
string get_record(string sQuest)
{
                string sName, sId;
                int nKilltime;
                
                nKilltime = DB_D->query_data("skybook/record/通关时间记录/" + DEBOOKS + "/" + sQuest + "/time");
                sName = DB_D->query_data("skybook/record/通关时间记录/" + DEBOOKS + "/" + sQuest + "/name");
                sId = DB_D->query_data("skybook/record/通关时间记录/" + DEBOOKS + "/" + sQuest + "/id");
                
                if (nKilltime == 0)return "暂无记录";
                        
                return sprintf("%d", nKilltime) + "秒，由 " + sName + "(" + sId + ") 创造"; 
}

void create()
{
        set_name("天书", ({ "skybook_xiaoaojianghu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 0);
                set_weight(0);
        }
        setup();
}

// 移动到剧情副本，flag代表任务编号
void move_to_room(object me, string nQuest)
{
        object obroom;
        int nKey;
        object ob;
        string sQuestInfo, *keys_QuestInfo, sNandu, *sTemp;
        string sID,sGender, sName, sHp, sDamage, sDefense, sSkill, sSkLevel, sType, sNextQuest;
        int nHp, nDamage, nDefense, nSkLevel;
        
        obroom = new("/clone/skybook14/sky14room");
        obroom->set("books", DEBOOKS);
        obroom->set("create_time", time());
        
        sNandu = me->query("skybook14/" + obroom->query("books") + "/难度");
        
        sQuestInfo = mSkybook_fuben[nQuest];
        keys_QuestInfo = explode(sQuestInfo, ":");
        
        // 根据配置设置房间名字和描述
        obroom->set_name(HIG + keys_QuestInfo[0] + "-" + keys_QuestInfo[1] + HIC + "(最快记录：" + get_record(nQuest) + ")", ({ "skybook" + sprintf("%d", time() + random(10)) }));
        obroom->set("long", keys_QuestInfo[2] + "\n");
        
  // 根据配置创建相应的BOSS和属性
  ob = new("/clone/skybook14/skybooknpc");

  sID = keys_QuestInfo[3];
  sName = keys_QuestInfo[4];
  sHp = keys_QuestInfo[5];
  sDamage = keys_QuestInfo[6];
  sDefense = keys_QuestInfo[7];
  sSkill = keys_QuestInfo[8];
  sSkLevel = keys_QuestInfo[9];
  sType = keys_QuestInfo[10];
  sNextQuest = keys_QuestInfo[11];
        sGender = keys_QuestInfo[12];   
        
  // 根据副本难度需要计算的数据
  if (sNandu == "少侠级")nKey = 0;
  else if (sNandu == "大侠级")nKey = 1;
  else nKey = 2;

  sHp = explode(sHp,"-")[nKey];
        sDamage = explode(sDamage,"-")[nKey];
        sDefense = explode(sDefense,"-")[nKey];
        sscanf(sSkLevel, "%d", nSkLevel);
        sscanf(sHp, "%d", nHp);
        sscanf(sDamage, "%d", nDamage);
        sscanf(sDefense, "%d", nDefense);
        sscanf(sSkLevel, "%d", nSkLevel);
        
        
  
  // 设置BOSS的任务编号及难度
  ob->set("books", obroom->query("books"));
        ob->set("nQuest", nQuest);
        ob->set("sNextQuest", sNextQuest);
        sTemp = explode(mSkybook_fuben[sNextQuest], ":");
        ob->set("sNextQuestZhangjie", sTemp[0]);
        ob->set("sNextQuestTitle", sTemp[1]);
        ob->set("sNandu", sNandu);
  ob->set("me", me);
  ob->set("skybookOBPath", __FILE__);
        ob->set("难度", sNandu);
        ob->set("born_room", obroom);

        ob->move(obroom);
        
        // 初始化BOSS
  ob->init_data(__FILE__,sGender,sID,sName,nHp,nDamage,nDefense,sSkill,nSkLevel,sType, sNandu);
  
        // 设置BOSS生成时间
        ob->set("create_time", time());

        me->move(obroom);
        
}

// 序章对话完毕后调用的回调接口，可以开始处理战斗副本开始了
void dialog_end(object me, int flag)
{

        if (! objectp(me))return;

        move_to_room(me, sprintf("%d", flag) );

        return;
}

// 来自 /cmds/usr/skybook.c调用，开始天书任务
void startbook(object me, string sBook)
{
        string sQuest; // 当前任务编号
        string sZhangjie; // 当前章节
        object ob, ob2;

        sZhangjie = me->query("skybook14/" + sBook + "/当前章节");
        sQuest = me->query("skybook14/" + sBook + "/任务编号"); // 表示还没有完成的任务编号
        

        if (sQuest == "1")
        {
                DIALOG_D->start_dialog4(this_object(), me, sBookMsg, 0, 1);
                return;
        }
        
        
        FUBEN_D->move_all_invalid_user(me);
        
        move_to_room(me, sQuest);

        return;

}

// 副本全部通关，大结局
void endskybook(object me)
{

        // 通知玩家完成了该天书
        tell_object(me, BLINK + HIY "\n恭喜你！成功通关《" + DEBOOKS + "》天书！\n\n" NOR);
        
        // 广播全服
        CHANNEL_D->do_channel(this_object(),"rumor", "听说" + HIY + me->query("name")  + "(" + me->query("id") + ")" HIM "闯关《" + DEBOOKS + "》天书成功！\n");
                
        log_file("0通关天书", me->query("id") + " at " + ctime(time()) + " 通关 " + DEBOOKS  + "\n" );
                
        // 累积该完成次数
        me->add("skybook14/option/" + DEBOOKS + "/completed_times", 1);
        
        // 给予通关固定奖励
        GIFT_D->delay_bonus(me,
                ([ "exp"      : 5000000,
                   "pot"      : 5000000,
                   "mar"      : 5000000,
                   "prompt"   : "你在通关《" +  DEBOOKS + "》天书后" ]), 999);  

        // 给予通关随机奖励
        SUICONG_D->give_end_gift(me, DEBOOKS, me->query("skybook14/" + DEBOOKS + "/难度"));

        return;
        
}