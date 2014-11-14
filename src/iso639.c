#include <stddef.h>
#include <strings.h>
#include "iso639.h"

static const struct {
  const char *iso639_1;
  const char *iso639_2t;
  const char *iso639_2b;
} iso639[] = {
  {"aa","aar",NULL},
  {"ab","abk",NULL},
  {"ae","ave",NULL},
  {"af","afr",NULL},
  {"ak","aka",NULL},
  {"am","amh",NULL},
  {"an","arg",NULL},
  {"ar","ara",NULL},
  {"as","asm",NULL},
  {"av","ava",NULL},
  {"ay","aym",NULL},
  {"az","aze",NULL},
  {"ba","bak",NULL},
  {"be","bel",NULL},
  {"bg","bul",NULL},
  {"bh","bih",NULL},
  {"bi","bis",NULL},
  {"bm","bam",NULL},
  {"bn","ben",NULL},
  {"bo","bod","tib"},
  {"br","bre",NULL},
  {"bs","bos",NULL},
  {"ca","cat",NULL},
  {"ce","che",NULL},
  {"ch","cha",NULL},
  {"co","cos",NULL},
  {"cr","cre",NULL},
  {"cs","ces","cze"},
  {"cu","chu",NULL},
  {"cv","chv",NULL},
  {"cy","cym","wel"},
  {"da","dan",NULL},
  {"de","deu","ger"},
  {"dv","div",NULL},
  {"dz","dzo",NULL},
  {"ee","ewe",NULL},
  {"el","ell","gre"},
  {"en","eng",NULL},
  {"eo","epo",NULL},
  {"es","spa",NULL},
  {"et","est",NULL},
  {"eu","eus","baq"},
  {"fa","fas","per"},
  {"ff","ful",NULL},
  {"fi","fin",NULL},
  {"fj","fij",NULL},
  {"fo","fao",NULL},
  {"fr","fra","fre"},
  {"fy","fry",NULL},
  {"ga","gle",NULL},
  {"gd","gla",NULL},
  {"gl","glg",NULL},
  {"gn","grn",NULL},
  {"gu","guj",NULL},
  {"gv","glv",NULL},
  {"ha","hau",NULL},
  {"he","heb",NULL},
  {"hi","hin",NULL},
  {"ho","hmo",NULL},
  {"hr","hrv","scr"},
  {"ht","hat",NULL},
  {"hu","hun",NULL},
  {"hy","hye","arm"},
  {"hz","her",NULL},
  {"ia","ina",NULL},
  {"id","ind",NULL},
  {"ie","ile",NULL},
  {"ig","ibo",NULL},
  {"ii","iii",NULL},
  {"ik","ipk",NULL},
  {"io","ido",NULL},
  {"is","isl","ice"},
  {"it","ita",NULL},
  {"iu","iku",NULL},
  {"ja","jpn",NULL},
  {"jv","jav",NULL},
  {"ka","kat","geo"},
  {"kg","kon",NULL},
  {"ki","kik",NULL},
  {"kj","kua",NULL},
  {"kk","kaz",NULL},
  {"kl","kal",NULL},
  {"km","khm",NULL},
  {"kn","kan",NULL},
  {"ko","kor",NULL},
  {"kr","kau",NULL},
  {"ks","kas",NULL},
  {"ku","kur",NULL},
  {"kv","kom",NULL},
  {"kw","cor",NULL},
  {"ky","kir",NULL},
  {"la","lat",NULL},
  {"lb","ltz",NULL},
  {"lg","lug",NULL},
  {"li","lim",NULL},
  {"ln","lin",NULL},
  {"lo","lao",NULL},
  {"lt","lit",NULL},
  {"lu","lub",NULL},
  {"lv","lav",NULL},
  {"mg","mlg",NULL},
  {"mh","mah",NULL},
  {"mi","mri","mao"},
  {"mk","mkd","mac"},
  {"ml","mal",NULL},
  {"mn","mon",NULL},
  {"mr","mar",NULL},
  {"ms","msa","may"},
  {"mt","mlt",NULL},
  {"my","mya","bur"},
  {"na","nau",NULL},
  {"nb","nob",NULL},
  {"nd","nde",NULL},
  {"ne","nep",NULL},
  {"ng","ndo",NULL},
  {"nl","nld","dut"},
  {"nn","nno",NULL},
  {"no","nor",NULL},
  {"nr","nbl",NULL},
  {"nv","nav",NULL},
  {"ny","nya",NULL},
  {"oc","oci",NULL},
  {"oj","oji",NULL},
  {"om","orm",NULL},
  {"or","ori",NULL},
  {"os","oss",NULL},
  {"pa","pan",NULL},
  {"pi","pli",NULL},
  {"pl","pol",NULL},
  {"ps","pus",NULL},
  {"pt","por",NULL},
  {"qu","que",NULL},
  {"rm","roh",NULL},
  {"rn","run",NULL},
  {"ro","ron","rum"},
  {"ru","rus",NULL},
  {"rw","kin",NULL},
  {"sa","san",NULL},
  {"sc","srd",NULL},
  {"sd","snd",NULL},
  {"se","sme",NULL},
  {"sg","sag",NULL},
  {"si","sin",NULL},
  {"sk","slk","slo"},
  {"sl","slv",NULL},
  {"sm","smo",NULL},
  {"sn","sna",NULL},
  {"so","som",NULL},
  {"sq","sqi","alb"},
  {"sr","srp","scc"},
  {"ss","ssw",NULL},
  {"st","sot",NULL},
  {"su","sun",NULL},
  {"sv","swe",NULL},
  {"sw","swa",NULL},
  {"ta","tam",NULL},
  {"te","tel",NULL},
  {"tg","tgk",NULL},
  {"th","tha",NULL},
  {"ti","tir",NULL},
  {"tk","tuk",NULL},
  {"tl","tgl",NULL},
  {"tn","tsn",NULL},
  {"to","ton",NULL},
  {"tr","tur",NULL},
  {"ts","tso",NULL},
  {"tt","tat",NULL},
  {"tw","twi",NULL},
  {"ty","tah",NULL},
  {"ug","uig",NULL},
  {"uk","ukr",NULL},
  {"ur","urd",NULL},
  {"uz","uzb",NULL},
  {"ve","ven",NULL},
  {"vi","vie",NULL},
  {"vo","vol",NULL},
  {"wa","wln",NULL},
  {"wo","wol",NULL},
  {"xh","xho",NULL},
  {"yi","yid",NULL},
  {"yo","yor",NULL},
  {"za","zha",NULL},
  {"zh","zho","chi"},
  {"zu","zul",NULL},
};

const char *find_iso639_1(const char *iso639_2)
{
  size_t n;
  if (!iso639_2) return NULL;
  for (n=0; n<sizeof(iso639)/sizeof(iso639[0]); ++n) {
    if (!strcasecmp(iso639_2,iso639[n].iso639_2t) || (iso639[n].iso639_2b && !strcasecmp(iso639_2,iso639[n].iso639_2b))) {
      return iso639[n].iso639_1;
    }
  }
  return NULL;
}
