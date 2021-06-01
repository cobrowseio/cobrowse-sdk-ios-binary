// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "CobrowseIO",
    platforms: [
        .macOS(.v10_10), .iOS(.v9)
    ],
    products: [
        .library(
            name: "CobrowseIO",
            targets: ["CobrowseIOTarget"])
    ],
    dependencies: [
        .package(
            name: "SwiftCBOR",
            url: "https://github.com/cobrowseio/SwiftCBOR",
            from: "0.4.4"),
        .package(
            name: "Starscream",
            url: "https://github.com/daltoniam/Starscream",
            from: "3.0.0")
    ],
    targets: [
        .target(
            name: "CobrowseIOTarget",
            dependencies: [.target(name: "CobrowseIOWrapper")],
            path: "CobrowseIOTarget"),
        .target(
            name: "CobrowseIOWrapper",
            dependencies: [
                .target(name: "CobrowseIO"),
                .product(name: "SwiftCBOR", package: "SwiftCBOR"),
                .product(name: "Starscream", package: "Starscream"),
            ],
            path: "CobrowseIOWrapper"),
        .binaryTarget(
            name: "CobrowseIO",
            path: "CobrowseIO.xcframework"),
    ]
)
