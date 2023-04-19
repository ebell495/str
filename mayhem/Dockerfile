FROM debian:bookworm as build
RUN apt update && apt install build-essential clang -y
COPY . /str
WORKDIR /str/fuzz

RUN make 

FROM debian:bookworm
COPY --from=build /str/fuzz/fuzz-str /fuzz-str
