/*Этот код демонстрирует работу библиотеки tex_streamer,
 * позволяющей генерировать TEX-документы с графикой из ROOT
 */
 
#include <TexStreamer.hh>
#include <TH1D.h>

void example_a4article()
{
	TEXDocument doc("article_a4_12pt_geometry_1cm");
	/*TEXDocument - класс для создания документов в TEX.
	 * В конструкторе задается тип документа (возможные варианты: "article_a4_12pt" - обычный вариант TEX, "article_a4_12pt_geometry_1cm" - с уменьшенными полями
	 * extarticle_a4_14pt - со шрифтом 14 (как в дипломах и т.д.
	 * beamer - для презентаций
	 * xelatex_article_a4_12pt,
	 * xelatex_article_a4_12pt_geometry_1cm
	 * xelatex_extarticle_a4_14pt
	 * xelatex_beamer - все то же самое для xelatex (позволяет ставить свои шрифты, и в целом, более красивый)
	 * стили задаются в preambles.json
	 * */
	doc<<string("Это очень важный документ, который демонстрирует возможности TEXStreamer. Вот, например, нарисуем гистограмму из root:\n");
	TH1D h("h","Гистограмма;Можно подписать оси на русском;А зачем?",100,-10,10);
	h.FillRandom("gaus",1000);
	TexStreamer tex;
	h.Draw("e hist");
	string picture=tex.CanvasToTEX();
	TEXFigure fig;
	fig<<picture<<"caption={Картинка №1} label={fig:fig1}";
	doc<<fig;
	doc<<"\n\nДействительно. Нужен еще мем сбоку\n";
	fig<<"memes/possible.png";
	doc<<fig;
	doc<<"\n\n Что-то крупновато. Сожмем правую часть мема!\n";
	fig<<"width={0.3}";//сожмем немного. Применяется к последнему изображению.
	doc<<fig;
	doc<<"\n\nА теперь еще и таблицу добавим:";
	TEXTable tab;
	tab<<"caption={Пример очень важной таблицы}"<<"$E_{\\gamma}$,кэВ"<<"$\\sigma$, мб"<<"\n";
	tab<<"110"<<24<<"\n";
	doc<<tab;
	doc<<"Ну такое. Добавим еще объединение ячеек!\n";
	tab<<"mc={2}Все это полная фигня!";
	doc<<tab;
	ofstream ofs("example_a4article.tex");
	ofs<<doc.Generate();
	ofs.close();
}
