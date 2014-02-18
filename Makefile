target:
	pdflatex main.tex
	pdflatex main.tex

clean:
	rm -rf *.aux
	rm -rf *.log
	rm -rf *.loc
	rm -rf *.toc
	rm -rf tex/*.log
	rm -rf tex/*.aux
  rm -rf *.pdf
